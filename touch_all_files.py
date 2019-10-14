#!/usr/bin/python3.6
'''
This script will append a new line to all .h/.cpp files.
'''
import os
import re

from pprint import pprint

target_ext_list = [re.compile(r".*?\.h"),
                    re.compile(r".*?\.cpp")]

ignore_dir_list = [re.compile(r".*?/extern/.*"),
                    re.compile(r".*?/build/.*"),
                    re.compile(r".*?/\..*")]

def dfs_get_all_files(target_dir, target_files):
    for f in os.listdir(target_dir):
        curr_path = os.path.join(target_dir, f)
        if os.path.isfile(curr_path):
            for target_ext_regex in target_ext_list:
                if target_ext_regex.match(curr_path):
                    target_files.append(curr_path)
                    break
        else:
            ignore_flag = False
            for ignore_dir_regex in ignore_dir_list:
                if ignore_dir_regex.match(curr_path):
                    ignore_flag = True
                    break
            if not ignore_flag:
                dfs_get_all_files(curr_path, target_files)

target_dir = '.'
target_files = []

dfs_get_all_files(target_dir, target_files)

pprint(target_files)

for target_file in target_files:
    with open(target_file, 'a') as fd:
        fd.write('\n')


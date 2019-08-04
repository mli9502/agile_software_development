TODO: 
- [ ] Add unit test.

Some issues encountered:
- When getting a `shared_ptr` of `this`, we can't just use `shared_ptr<T>(this)`, instead, we have to use `shared_from_this()`. [ref](https://stackoverflow.com/questions/11711034/stdshared-ptr-of-this)
- Can't initialize multiple `shared_ptr` from a single raw pointer. This is because when these `shared_ptr`s are created by `sharted_ptr<T>(T*)`, they will use different control blocks. And, as a result, the reference count can not be correctly tracked. 
  When one of these `shared_ptr`s is out of scope, it will destroy the object on heap, and will leave the other `shared_ptr`s in invalid state. [ref](https://stackoverflow.com/questions/10338606/multiple-shared-ptr-storing-same-pointer)
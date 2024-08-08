
DtwLockerModule newDtwLockerModule(){
    DtwLockerModule  self = {0};
    self.newLocker = newDtwLocker;
    self.lock = DtwLocker_lock;
    self.unlock = DtwLocker_unlock;
    self.represemt = DtwLocker_represemt;
    self.free = DtwLocker_free;
    return self;
}
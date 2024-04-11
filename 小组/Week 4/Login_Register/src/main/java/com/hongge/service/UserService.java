package com.hongge.service;

import com.hongge.pojo.User;

public interface UserService {
    User Login(User user);

    void Register(User user);
}

package com.hongge.mapper;

import com.hongge.pojo.User;

import java.util.List;

public interface UserMapper {
    /**
    以用户名以及密码查找用户
     */
    User select(User user);

    void register(User user);
}

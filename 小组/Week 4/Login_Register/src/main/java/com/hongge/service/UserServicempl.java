package com.hongge.service;

import com.hongge.mapper.UserMapper;
import com.hongge.pojo.User;
import com.hongge.utils.sqlSessionFactoryUtil;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;

import java.sql.Connection;
import java.util.List;

public class UserServicempl implements UserService{
    SqlSessionFactory factory= sqlSessionFactoryUtil.getSqlSessionFactory();
    @Override
    public User Login(User user){
        //2.获取sqlsession对象
        SqlSession sqlSession=factory.openSession();
        //3.获取Mapper
        UserMapper mapper=sqlSession.getMapper(UserMapper.class);
        //4.调用方法
        User user1=mapper.select(user);
        //5.释放资源
        sqlSession.close();
        return user1;
    }
    @Override
    public void Register(User user){
        //2.获取sqlsession对象
        SqlSession sqlSession=factory.openSession();
        //3.获取Mapper
        UserMapper mapper=sqlSession.getMapper(UserMapper.class);
        //4.调用方法
        mapper.register(user);
        //提交事务
        sqlSession.commit();
        //5.释放资源
        sqlSession.close();
    }
}

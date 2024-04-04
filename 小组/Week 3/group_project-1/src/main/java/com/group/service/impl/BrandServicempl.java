package com.group.service.impl;

import com.group.mapper.BrandMapper;
import com.group.pojo.Brand;
import com.group.service.BrandService;
import com.group.utils.sqlSessionFactoryUtil;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;

import java.util.List;

public class BrandServicempl implements BrandService {
//1.创建sqlsessionfactory对象
    SqlSessionFactory factory= sqlSessionFactoryUtil.getSqlSessionFactory();
    @Override
    public List<Brand> selectAll() {
        //2.获取sqlsession对象
        SqlSession sqlSession=factory.openSession();
        //3.获取BrandMapper
        BrandMapper mapper=sqlSession.getMapper(BrandMapper.class);
        //4.调用方法
        List<Brand> brands=mapper.selectAll();
        //5.释放资源
        sqlSession.close();
        return brands;
    }

    @Override
    public void add(Brand brand) {
        //2.获取sqlsession对象
        SqlSession sqlSession=factory.openSession();
        //3.获取BrandMapper
        BrandMapper mapper=sqlSession.getMapper(BrandMapper.class);
        //4.调用方法
        mapper.add(brand);
        //提交事务
        sqlSession.commit();
        //5.释放资源
        sqlSession.close();
    }
    @Override
    public void delete(int id){
        //2.获取sqlsession对象
        SqlSession sqlSession=factory.openSession();
        //3.获取BrandMapper
        BrandMapper mapper=sqlSession.getMapper(BrandMapper.class);
        //4.调用方法
        mapper.delete(id);
        //提交事务
        sqlSession.commit();
        //5.释放资源
        sqlSession.close();
    }
}

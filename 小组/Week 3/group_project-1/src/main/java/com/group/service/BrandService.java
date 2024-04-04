package com.group.service;

import com.group.pojo.Brand;

import java.util.List;

public interface BrandService {
    //查询所有
    List<Brand> selectAll();

    void add(Brand brand);
    void delete(int id);
}

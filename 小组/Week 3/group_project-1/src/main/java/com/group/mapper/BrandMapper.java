package com.group.mapper;

import com.group.pojo.Brand;
import org.apache.ibatis.annotations.Insert;

import java.util.List;

public interface BrandMapper {
    //查询所有数据
    List<Brand>selectAll();

    void add(Brand brand);

    void delete(int id);
}

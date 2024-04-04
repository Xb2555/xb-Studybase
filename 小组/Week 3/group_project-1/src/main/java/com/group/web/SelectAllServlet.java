package com.group.web;

import com.alibaba.fastjson.serializer.SerializerFeature;
import com.alibaba.fastjson.JSON;
import com.group.pojo.Brand;
import com.group.service.BrandService;
import com.group.service.impl.BrandServicempl;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;
import com.alibaba.*;
@WebServlet("/selectAll")
public class SelectAllServlet extends HttpServlet {
    BrandService brandService=new BrandServicempl();
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.addHeader("content-type", "text/html;charset=utf-8");
        List<Brand> brands=brandService.selectAll();
        //将集合转换为json数据
        String jsonString = JSON.toJSONString(brands);
        //响应数据
        response.setContentType("text/jason;charset=GBK");
        response.getWriter().write(jsonString);
    }
    @Override
    protected void doPost(HttpServletRequest request,HttpServletResponse response) throws IOException {
        this.doGet(request,response);
    }
}

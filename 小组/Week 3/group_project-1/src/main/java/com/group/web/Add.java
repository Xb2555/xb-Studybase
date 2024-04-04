package com.group.web;

import com.alibaba.fastjson.JSON;
import com.group.pojo.Brand;
import com.group.service.BrandService;
import com.group.service.impl.BrandServicempl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.nio.Buffer;

/**
 * @author 20127
 */
@WebServlet("/add")
public class Add extends HttpServlet {
    BrandService brandService=new BrandServicempl();
   @Override
   protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
       request.setCharacterEncoding("utf-8");
       //1.获取请求体数据
       BufferedReader br=request.getReader();
       String params=br.readLine();

       //2.将json字符串转为java对象
       Brand brand= JSON.parseObject(params,Brand.class);
       brandService.add(brand);

       //3.响应成功标识
       response.getWriter().write("success");
   }
   @Override
    protected void doPost(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
       this.doGet(request,response);
   }
}

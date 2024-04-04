package com.group.web;

import com.group.service.BrandService;
import com.group.service.impl.BrandServicempl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * @author 20127
 */
@WebServlet("/delete")
public class Delete extends HttpServlet {
    BrandService brandService=new BrandServicempl();
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        //获取id
        String id=request.getParameter("id");
        //执行sql语句
        brandService.delete(Integer.parseInt(id));
        //响应状态
        response.getWriter().write("success");
        response.sendRedirect("http://localhost:8080/group_project_1_war/brand.html");
    }
    @Override
    protected void doPost(HttpServletRequest request,HttpServletResponse response) throws IOException, ServletException {
        this.doGet(request,response);
    }
}

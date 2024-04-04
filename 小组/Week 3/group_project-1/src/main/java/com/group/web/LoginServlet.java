package com.group.web;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.Part;
import java.io.IOException;
@WebServlet("/Login")
public class LoginServlet extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }

    @Override
    protected void doPut(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setStatus(HttpServletResponse.SC_NOT_IMPLEMENTED);
        resp.getWriter().write("put request is not implemented");
    }

    @Override
    protected void doDelete(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String id=req.getParameter("id");
        //此处省略删除数据库数据操作
        resp.getWriter().write(id+" is deleted");
    }

    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setHeader("ALLOW","GET,POST");
        resp.setStatus(HttpServletResponse.SC_OK);
    }

    //文件上传
    /*@Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        System.out.println("文件上传");
        //获取part对象
        Part part=req.getPart("myfile");
        String filename=part.getSubmittedFileName();
        System.out.println("上传文件名为"+filename);
        //得到文件存放路径
        String filepath= req.getServletPath();
        System.out.println("文件存放路径为："+filepath);
        //上传文件到指定目录
        part.write(filepath+"/"+filename);
    }
*/
    @Override
    protected void doGet(javax.servlet.http.HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String name=req.getParameter("name");
        resp.getWriter().write("This is your get name:"+name);
    }
}

package com.hongge.web;

import com.alibaba.fastjson.JSON;
import com.hongge.pojo.User;
import com.hongge.service.UserService;
import com.hongge.service.UserServicempl;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
@WebServlet("/User")
public class UserServlet extends BaseServlet{
    private UserService service = new UserServicempl();
    public void Login(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/json;charset=utf-8");
        request.setCharacterEncoding("utf-8");
        //获取id和密码
        BufferedReader br=request.getReader();
        String params=br.readLine();
        User user=JSON.parseObject(params,User.class);
       //传入方法
        User user1= service.Login(user);
        //响应数据
        if(user1 != null){
           response.getWriter().write("succeed");
        }else{
            response.getWriter().write("failed");
        }
    }
    public void Register(HttpServletRequest request,HttpServletResponse response) throws IOException {
        response.setContentType("text/json;charset=utf-8");
        request.setCharacterEncoding("utf-8");
        //获取json数据
        BufferedReader br=request.getReader();
        String params=br.readLine();
        //将json字符串转换为java类
        User user=JSON.parseObject(params,User.class);
        //调用方法
        service.Register(user);
        //响应
        if(user.getId()!=null) {
            response.getWriter().write("succeed");
        }else{
            response.getWriter().write("failed");
        }
    }
}

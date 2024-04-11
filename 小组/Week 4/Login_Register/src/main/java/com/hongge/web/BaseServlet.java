package com.hongge.web;

import com.hongge.service.UserService;
import com.hongge.service.UserServicempl;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class BaseServlet extends HttpServlet {
    @Override
    protected  void doGet(HttpServletRequest request,HttpServletResponse response){
        //获取方法名
        String methodName=request.getParameter("methodName");
        //获取字节码文件
        Class<? extends BaseServlet> cls=this.getClass();
        try{
            //获取方法method
            Method method =cls.getMethod(methodName,HttpServletRequest.class,HttpServletResponse.class);
            //执行方法
            method.invoke(this,request,response);
        } catch (NoSuchMethodException | IllegalAccessException | InvocationTargetException e){
            throw new RuntimeException(
                    "您调用的" + methodName + "(HttpServletRequest request , HttpServletResponse response)方法不存在", e);
        }
    }
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response){
        this.doGet(request,response);
    }
}

package util;
import java.io.FileReader;
import java.io.IOException;
import java.net.URL;
import java.sql.*;
import java.util.Properties;

public class JDBCUtils {
    //创建成员变量
    private static String url;//数据库名称
    private static String user;//用户名
    private static String password;//密码
    private static String driver;//驱动
    //jdbc.properties配置文件的读取
    static{

        try{
            //1.创建properties集合类
            Properties properties=new Properties();
            //获取src路径下的文件的方法-Classloder 加载器
            ClassLoader classLoader=JDBCUtils.class.getClassLoader();
            URL res =classLoader.getResource("jdbc.properties");
            String path =res.getPath();
            //2.加载文件
            properties.load(new FileReader(path));
            url =properties.getProperty("url");
            password =properties.getProperty("password");
            driver = properties.getProperty("driver");
            //注册驱动
            Class.forName(driver);
        }catch (IOException e){
            e.printStackTrace();
        }catch (ClassNotFoundException e){
            e.printStackTrace();;
        }
    }
    //获取连接
    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url,user,password);
    }
    //释放资源
    public static void close(Statement statement, Connection connection){
        if(statement!=null){
            try{
                statement.close();
            }catch(SQLException throwables){
                throwables.printStackTrace();
            }
        }
        if(connection!=null){
            try{
                connection.close();
            }catch(SQLException throwables){
                throwables.printStackTrace();
            }
        }
    }
    //释放资源
    public static void close(Statement statement, Connection connection, ResultSet resultSet){
        if (resultSet != null) {
            try {
                resultSet.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        if (statement != null) {
            try {
                statement.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        if (connection != null) {
            try {
                connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

    }
}

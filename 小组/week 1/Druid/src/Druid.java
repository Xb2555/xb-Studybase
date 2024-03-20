import com.alibaba.druid.pool.DruidDataSource;
import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.FileInputStream;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;

public class Druid {
    public static DataSource dataSource;
    static {
        try{
            //1.导入配置文件，初始化数据库池
            Properties prop=new Properties();
            prop.load(new FileInputStream("src/druid.properties"));
            //获取连接池对象：dataSource
            dataSource = DruidDataSourceFactory.createDataSource(prop);
        }catch(Exception e){
            e.printStackTrace();
        }
    }
    //2.创建数据库池连接
    public static Connection getConnection(){
        try{
            return dataSource.getConnection();
        }catch(SQLException e){
            e.printStackTrace();
        }
        return null;
    }
    //3.关闭连接，后开后关
    public static void closeAll(Connection conn, ResultSet res, Statement stmt) throws SQLException {
        try{
            if(res!=null){
                res.close();
            }
            if(stmt!=null){
                stmt.close();
            }
            if(conn!=null){
                conn.close();
            }
        }catch(SQLException e){
            e.printStackTrace();
        }
    }
}

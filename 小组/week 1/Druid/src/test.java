import java.sql.Connection;
import java.sql.SQLException;

public class test {
    public static void main(String[] args) throws SQLException {
       for(int i=0;i<5;i++){
           Connection conn=Druid.getConnection();
           System.out.println(conn.toString()+"\n-----------------");
           Druid.closeAll(conn,null,null);
       }
    }
}

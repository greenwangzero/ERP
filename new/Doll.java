import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.util.HashMap;
import java.util.Map;

import net.sf.json.JSONObject;
public class Doll {
    public static final String DEF_CHATSET = "UTF-8";
        public static final int DEF_CONN_TIMEOUT = 30000;
        public static final int DEF_READ_TIMEOUT = 30000;
        public static String userAgent =  "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/29.0.1547.66 Safari/537.36";

        //配置您申请的KEY
        public static final String APPKEY ="50cf26dbac0ed4fbaf54fa2cf24ac1d6";

        //1.常用汇率查询
        public static void getRequest1(){
            String result =null;
            String url ="http://op.juhe.cn/onebox/exchange/query";//请求接口地址
            Map params = new HashMap();//请求参数
                params.put("key",APPKEY);//应用APPKEY(应用详细页查询)

            try {
                result =net(url, params, "GET");
                JSONObject object = JSONObject.fromObject(result);
                if(object.getInt("error_code")==0){
                    System.out.println(object.get("result"));
                }else{
                    System.out.println(object.get("error_code")+":"+object.get("reason"));
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        //2.货币列表
        public static void getRequest2(){
            String result =null;
            String url ="http://op.juhe.cn/onebox/exchange/list";//请求接口地址
            Map params = new HashMap();//请求参数
                params.put("key",APPKEY);//应用APPKEY(应用详细页查询)

            try {
                result =net(url, params, "GET");
                JSONObject object = JSONObject.fromObject(result);
                if(object.getInt("error_code")==0){
                    System.out.println(object.get("result"));
                }else{
                    System.out.println(object.get("error_code")+":"+object.get("reason"));
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        //3.实时汇率查询换算
        public static void getRequest3(){
            String result =null;
            String url ="http://op.juhe.cn/onebox/exchange/currency";//请求接口地址
            Map params = new HashMap();//请求参数
                params.put("from","");//转换汇率前的货币代码
                params.put("to","");//转换汇率成的货币代码
                params.put("key",APPKEY);//应用APPKEY(应用详细页查询)

            try {
                result =net(url, params, "GET");
                JSONObject object = JSONObject.fromObject(result);
                if(object.getInt("error_code")==0){
                    System.out.println(object.get("result"));
                }else{
                    System.out.println(object.get("error_code")+":"+object.get("reason"));
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }



        public static void main(String[] args) {

        }

        /**
         *
         * @param strUrl 请求地址
         * @param params 请求参数
         * @param method 请求方法
         * @return  网络请求字符串
         * @throws Exception
         */
        public static String net(String strUrl, Map params,String method) throws Exception {
            HttpURLConnection conn = null;
            BufferedReader reader = null;
            String rs = null;
            try {
                StringBuffer sb = new StringBuffer();
                if(method==null || method.equals("GET")){
                    strUrl = strUrl+"?"+urlencode(params);
                }
                URL url = new URL(strUrl);
                conn = (HttpURLConnection) url.openConnection();
                if(method==null || method.equals("GET")){
                    conn.setRequestMethod("GET");
                }else{
                    conn.setRequestMethod("POST");
                    conn.setDoOutput(true);
                }
                conn.setRequestProperty("User-agent", userAgent);
                conn.setUseCaches(false);
                conn.setConnectTimeout(DEF_CONN_TIMEOUT);
                conn.setReadTimeout(DEF_READ_TIMEOUT);
                conn.setInstanceFollowRedirects(false);
                conn.connect();
                if (params!= null && method.equals("POST")) {
                    try {
                        DataOutputStream out = new DataOutputStream(conn.getOutputStream());
                            out.writeBytes(urlencode(params));
                    } catch (Exception e) {
                        // TODO: handle exception
                    }
                }
                InputStream is = conn.getInputStream();
                reader = new BufferedReader(new InputStreamReader(is, DEF_CHATSET));
                String strRead = null;
                while ((strRead = reader.readLine()) != null) {
                    sb.append(strRead);
                }
                rs = sb.toString();
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                if (reader != null) {
                    reader.close();
                }
                if (conn != null) {
                    conn.disconnect();
                }
            }
            return rs;
        }

        //将map型转为请求参数型
        public static String urlencode(Map<String,Object>data) {
            StringBuilder sb = new StringBuilder();
            for (Map.Entry i : data.entrySet()) {
                try {
                    sb.append(i.getKey()).append("=").append(URLEncoder.encode(i.getValue()+"","UTF-8")).append("&");
                } catch (UnsupportedEncodingException e) {
                    e.printStackTrace();
                }
            }
            return sb.toString();
        }
}

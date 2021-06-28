package great.doctor.sincerity;

public class Main {

    private static String accessKey = "3b78a66b1bb04183a0215b7b8e6e18e9";
    private static String apiservice = "hssServives";
    private static String timestamp = "1623325847266";
    private static String version = "1.0.0";
    private static String secretKey = "4txZk+mhrU/JMLXmyP5m3S4Rc20=";

    public static void main(String[] args) {

        try {
            String params = "_api_access_key=" + accessKey + "&_api_name=" + apiservice + "&_api_timestamp=" + timestamp + "&_api_version=" + version;
            Signature signature = new Signature();
            System.out.println("java : " + signature.Sign(params, secretKey));
//            SignJni jni = new SignJni();
//            System.out.println("cpp : " + jni.getSign(params, secretKey));
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}

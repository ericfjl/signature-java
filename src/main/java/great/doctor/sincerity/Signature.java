package great.doctor.sincerity;

import javax.crypto.Mac;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

public class Signature {

    private static String MAC_NAME = "HmacSHA1";
    private static String ENCODING = "UTF-8";

    public String Sign(String encryptText, String encryptKey) {
        try {

            byte[] preSign = HmacSHA1Encrypt(encryptText, encryptKey);
            String sign = Base64.getEncoder().encodeToString(preSign);
            return sign;
        } catch (Exception e) {
            e.printStackTrace();
            return "";
        }
    }

    public byte[] HmacSHA1Encrypt(String encryptText, String encryptKey) throws Exception {

        byte[] data = encryptKey.getBytes(ENCODING);
        SecretKey secretKey = new SecretKeySpec(data, MAC_NAME);
        Mac mac = Mac.getInstance(MAC_NAME);
        mac.init(secretKey);

        byte[] text = encryptText.getBytes(ENCODING);
        return mac.doFinal(text);
    }
}

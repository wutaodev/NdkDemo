package org.wutao.ndkdemo;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    private ImageView mImageView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        mImageView = (ImageView) findViewById(R.id.test_img);
    }

    public void btnGetKet(View view) {
        String appKey = NativeHelper.getAppKeyFromC();
        String appSecret = NativeHelper.getAppSecretFromC();
        Log.d(TAG, "appkey: " + appKey);
        Log.d(TAG, "appSecret: " + appSecret);

        NativeHelper.sayHello("hello,world");

        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.mipmap.ic_launcher);
        int height = bitmap.getHeight();
        int width = bitmap.getWidth();
        int size = width * height;
        int[] colors = new int[size];
        bitmap.getPixels(colors, 0, width, 0, 0, width, height);

        colors = NativeHelper.convertBitmap(colors, width, height);
        bitmap.recycle();
        bitmap = Bitmap.createBitmap(colors, width, height, Bitmap.Config.ARGB_8888);
        mImageView.setImageBitmap(bitmap);


    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }


}

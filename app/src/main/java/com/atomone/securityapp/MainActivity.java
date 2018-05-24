package com.atomone.securityapp;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;

import com.atomone.Secureinspect.SecureSDK;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        findViewById(R.id.btn_debug).setOnClickListener(v -> System.out.println(SecureSDK.getInstance().debugCheck()));
        findViewById(R.id.btn_root).setOnClickListener(v -> System.out.println(SecureSDK.getInstance().rootCheck()));
        findViewById(R.id.btn_emulator).setOnClickListener(v -> System.out.println(SecureSDK.getInstance().emulatorCheck(this)));
        findViewById(R.id.btn_hook).setOnClickListener(v -> System.out.println(SecureSDK.getInstance().injectCheck()));

        findViewById(R.id.btn_va).setOnClickListener(v -> System.out.println(SecureSDK.getInstance().isRunInVa(this)));
        findViewById(R.id.btn_multi_open).setOnClickListener(v -> System.out.println(SecureSDK.getInstance().isMultiOpen(this)));
    }
}

package com.atomone.Secureinspect;

import android.text.TextUtils;

/**
 * @author Administrator
 */
public class SecureException extends RuntimeException {

    private String errorCode;

    public SecureException(String message) {
        super(message);
    }

    public SecureException(String errorCode, String message) {
        super(message);
        this.errorCode = errorCode;
    }

    @Override
    public String getMessage() {
        if (TextUtils.isEmpty(errorCode)) {
            return super.getMessage();
        }
        return errorCode + "  " + super.getMessage();
    }
}

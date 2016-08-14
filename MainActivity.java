package com.example.android.justjava;

import android.annotation.TargetApi;
import android.icu.text.NumberFormat;
import android.os.Build;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private int order=0;
    private final int prices=5;
    private final int creama=2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void orderButton(View view) {
        displayPrice(order * prices);
    }


    public void increasingButton(View view) {
        ++order;
        display(order);
    }

    public void decreasingButton(View view){

      order = (order == 0)? 0 : --order;
      display(order);
    }


    private void displayPrice(int number)
    {

        TextView priceTextView =(TextView)
                findViewById(R.id.price_text_view);
        CheckBox checkBox = (CheckBox)
                findViewById(R.id.checkBox);

        priceTextView.setText(ordering(order,prices,"mohamed",
                checkBox.isChecked()));
    }

    private void display(int number) {
        TextView quantityTextView = (TextView)
                findViewById(R.id.quantity_text_view);
        quantityTextView.setText(String.valueOf(number));
    }

    private String ordering(int quemtity,int prices,String name,boolean cream){

        String result = "Name: "+name
                   +"\nQuantity: "+quemtity
                   +"\nTotal: $"
                    +creamIsAble(cream,quemtity)
                    +"Thank You!";

        return result;
    }

    private String creamIsAble(boolean cream,int quemtity){
        if(cream)
            return ((creama*quemtity)+
                    (order*prices)) +
                    "\nWithCream\n";
        else
            return (order)*prices+"\n";
    }
}


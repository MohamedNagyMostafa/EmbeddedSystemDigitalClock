package com.example.android.justjava;

import android.annotation.TargetApi;
import android.icu.text.NumberFormat;
import android.os.Build;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private int order=0;
    private final int oneCoffee =5;
    private final int creamCost=2;
    private final int chocolateCost = 2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void orderButton(View view) {
        displayPrice(order * oneCoffee);
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
        CheckBox checkBoxcho = (CheckBox)
                findViewById(R.id.checkBoxCh);
        EditText name = (EditText)
                findViewById(R.id.textBox);

        priceTextView.setText(ordering(number,name.getText().toString(),
                checkBox.isChecked(),checkBoxcho.isChecked()));
    }

    private void display(int number) {
        TextView quantityTextView = (TextView)
                findViewById(R.id.quantity_text_view);
        quantityTextView.setText(String.valueOf(number));
    }

    private String ordering(int money,String name,
                            boolean cream,boolean chocolate){

        String result = "Name: "+name
                +"\nQuantity: "+order
                +checkTopping(cream,chocolate,money)
                +"\nThank You!";

        return result;
    }

    private String checkTopping(boolean cream,boolean chocolate,
                                int money){
        String ordering = "";

        if(cream){
            money = money + (creamCost * order);
            ordering = ordering + "\nCreama is added";}

        if(chocolate){
            money = money + (chocolateCost * order);
            ordering = ordering + "\nChocolate is added";}
        return ordering+"\nTotal: $"+money;
    }
}

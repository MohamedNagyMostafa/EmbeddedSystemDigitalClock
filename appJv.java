package com.example.android.courtcounter;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private int scoreTeamA = 0;
    private int scoreTeamB = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void addThreePointsA(View view) {
        displayTeamAScore(scoreTeamA+=3);
    }

    public void addTwoPointsA(View view){
        displayTeamAScore(scoreTeamA+=3);
    }

    public void addOnePointA(View view){
        displayTeamAScore(++scoreTeamA);
    }
    public void addThreePointsB(View view) {
        displayTeamBScore(scoreTeamB+=3);
    }

    public void addTwoPointsB(View view){
        displayTeamBScore(scoreTeamB+=3);
    }

    public void addOnePointB(View view){
        displayTeamBScore(++scoreTeamB);
    }

    public void Reset(View view){
        displayTeamAScore(scoreTeamA = 0);
        displayTeamBScore(scoreTeamB = 0);
    }

    private void displayTeamAScore(int scoreTeamA){
        TextView score = (TextView) findViewById(
                R.id.scoreTeamA);
        score.setText(String.valueOf(scoreTeamA));
    }

    private void displayTeamBScore(int scoreTeamB){
        TextView score = (TextView) findViewById(
                R.id.scoreTeamB);
        score.setText(String.valueOf(scoreTeamB));
    }
}

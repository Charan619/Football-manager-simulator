#include "Match.h"
#include <time.h>
#include<time.h>

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

Match::Match()
{
    game_week=0;
}

void Match::Game(Team &t1,Team &t2,char *id)
{
    system("cls");
    t1.inc_matches();
    t2.inc_matches();
    fflush(stdin);
    float t1_att=0,t1_def=0,t2_def=0,t2_att=0;
    //calculating att and def of both teams
    for(int j=0;j<11;j++)
    {
        int i=t1.get_start11(j);
        switch(t1.player(i).Gettype())
        {

            case 1:t1_att+=(t1.player(i).Getpac()+t1.player(i).Getdri()+t1.player(i).Getsho());break;
            case 2:
                    {
                        t1_att+=0.5*(t1.player(i).Getpac()+t1.player(i).Getdri()+t1.player(i).Getsho()+t1.player(i).Getphy()+t1.player(i).Getpas());
                        t1_def+=0.5*(t1.player(i).Getpac()+t1.player(i).Getdri()+t1.player(i).Getdef()+t1.player(i).Getphy()+t1.player(i).Getpas());
                        break;
                    }
            case 3:t1_def+=(t1.player(i).Getphy()+t1.player(i).Getdef()+t1.player(i).Getpas());break;
            case 4:t1_def+=(t1.player(i).Getpac()+t1.player(i).Getdri()+t1.player(i).Getphy());break;
        }
        cout<<t1_att<<" "<<t1_def<<endl;
        cout<<t2.player(i).Getname()<<t2.player(i).Getpac();

        i=t2.get_start11(j);
        switch(t2.player(i).Gettype())
        {

            case 1:t2_att+=(t2.player(i).Getpac()+t2.player(i).Getdri()+t2.player(i).Getsho());break;
            case 2:
                    {
                        cout<<"Mid";
                        t2_att+=0.5*(t2.player(i).Getpac()+t2.player(i).Getdri()+t2.player(i).Getsho()+t2.player(i).Getphy()+t2.player(i).Getpas());
                        t2_def+=0.5*(t2.player(i).Getpac()+t2.player(i).Getdri()+t2.player(i).Getdef()+t2.player(i).Getphy()+t2.player(i).Getpas());
                        break;
                    }
            case 3:t2_def+=(t2.player(i).Getphy()+t2.player(i).Getdef()+t2.player(i).Getpas());break;
            case 4:t2_def+=(t2.player(i).Getpac()+t2.player(i).Getdri()+t2.player(i).Getphy());break;
        }
        cout<<t2_att<<" "<<t2_def<<endl;
    }

    int mod=1;

    if(t1.Get_attack_style()!=t2.Get_defence_style())
    {
        if(t1.Get_attack_style()==1)
        {
            if(t2.Get_defence_style()==3)
                mod=1.4;
            if(t2.Get_defence_style()==2)
                mod=1.2;
        }

        else if(t1.Get_attack_style()==3)
        {
            if(t2.Get_defence_style()==1)
                mod=1.4;
            if(t2.Get_defence_style()==2)
                mod=1.2;
        }

        else if(t1.Get_attack_style()==2)
            mod=1.2;
    }
    t1_att*=mod;

    mod=1;

    if(t2.Get_attack_style()!=t1.Get_defence_style())
    {
        if(t2.Get_attack_style()==1)
        {
            if(t1.Get_defence_style()==3)
                mod=1.4;
            if(t1.Get_defence_style()==2)
                mod=1.2;
        }

        else if(t2.Get_attack_style()==3)
        {
            if(t1.Get_defence_style()==1)
                mod=1.4;
            if(t1.Get_defence_style()==2)
                mod=1.2;
        }

        else if(t2.Get_attack_style()==2)
            mod=1.2;
    }
    t2_att*=mod;

    mod=1;
    if(t1.Get_attack_width()==1)
    {
        if(t2.Get_defence_width()==1)
            mod=1.4;
        else if(t2.Get_defence_width()==2)
            mod=1.2;
    }
    else if(t1.Get_attack_width()==3)
    {
        if(t2.Get_defence_width()==3)
            mod=1.4;
        else if(t2.Get_defence_width()==2)
            mod=1.2;
    }
    else
    {
        if(t2.Get_defence_width()==2)
            mod=1.3;
        else
            mod=1.2;
    }
    t1_def*=mod;

    mod=1;
    if(t2.Get_attack_width()==1)
    {
        if(t1.Get_defence_width()==1)
            mod=1.4;
        else if(t1.Get_defence_width()==2)
            mod=1.2;
    }
    else if(t2.Get_attack_width()==3)
    {
        if(t1.Get_defence_width()==3)
            mod=1.4;
        else if(t1.Get_defence_width()==2)
            mod=1.2;
    }
    else
    {
        if(t1.Get_defence_width()==2)
            mod=1.3;
        else
            mod=1.2;
    }
    t2_def*=mod;







    system("pause");
    int a1=0,b1=0,att,def;
    int fl=0,t=0,padding=2380;

//simming game
    while(t!=90)
    {


        if(t%10==5)
        {
            att=t1_att;
            def=t2_def;
            fl=1;
        }
        else
        {
            att=t2_att;
            def=t1_def;
            fl=2;
        }
        int c=att+def+padding;
        //generating rand no
        int r=rand() % c + 1;
        int time=(rand() % 5 )+ t;
        if(fl==1&&r<att)
        {
            a1++;
            t1.inc_goals_for();
            t2.inc_goals_against();
            fl=3;
        }
        if(fl==2&&r<att)
        {
            b1++;
            t2.inc_goals_for();
            t1.inc_goals_against();
            fl=3;
        }
        //if(r>c-def)
        //{
          //  b1++;
            //fl=2;
        //}
        int dly=0;
        if(strcmpi(t1.Getteam_name(),id)==0||strcmpi(t2.Getteam_name(),id)==0)
        while(dly!=5)
        {
            system("cls");

            cout<<t+dly<<endl;
            cout<<t1.Getteam_code()<<"  "<<a1<<" : "<<b1<<"  "<<t2.Getteam_code();
            if(fl==3&&t+dly==t)
                cout<<"\nGOALLL!!"<<"  ' "<<t;
            cout<<endl;
            dly++;
            delay(300);

        }
        else if(t==85)
        {
            cout<<"FULL TIME\n";
            cout<<t1.Getteam_code()<<"  "<<a1<<" : "<<b1<<"  "<<t2.Getteam_code();
        }
        t+=5;
        padding-=5;
        fl=0;
    }
    if (a1>b1)
    {
        t1.Setpts(t1.Getpts()+3);
        t1.Setwin(t1.Getwin()+1);
        t2.Setloss(t2.Getloss()+1);
    }
    else if (a1<b1)
    {
        t2.Setpts(t2.Getpts()+3);
        t2.Setwin(t2.Getwin()+1);
        t1 .Setloss(t1.Getloss()+1);
    }
    else
    {
        t1.Setpts(t1.Getpts()+1);
        t2.Setpts(t2.Getpts()+1);
        t2.Setdraw(t2.Getdraw()+1);
        t1 .Setdraw(t1.Getdraw()+1);
    }
    t1.Setgoals_diff(t1.Getgoals_for()-t1.Getgoals_against());
    t2.Setgoals_diff(t2.Getgoals_for()-t2.Getgoals_against());

}

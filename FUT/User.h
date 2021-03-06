#ifndef USER_H
#define USER_H
#include<conio.h>
#include "Match.h"
#include "Manage.h"
#include "Team.h"

class User : public Match,public Manage
{
    public:
        User(int,int);
        void TableWrite(Team*,char*);
        int Getteam_id() { return team_id; }
        void Setteam_id(int val) { team_id = val; }
        int Getuser_id() { return user_id; }
        void Setuser_id(int val) { user_id = val; }
        char* Getuser_name() { return user_name; }
        void Setuser_name(char* val) { user_name = val; }
        void load_table();
        void save_table();
    protected:
    private:
        int team_id;
        int user_id;
        char* user_name;
        int schedule[10][9];
};

#endif // USER_H

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;




class Streaming{

    
    


    public:

    string name,nameUnedited, genre,genreUnedited, info;
    float score;

    int length;
    

    Streaming(){
        name = "";
        length = 0.0;
        genre = "";
        score = 0.0;
        setInfo();
    };

    Streaming(string nombre, int duracion, string genero,  float calificacion){
        setStream(nombre, duracion, genero,calificacion);

        
        

        
        

        






    }

    void setStream(string nombre, int duracion, string genero,  float calificacion){


        

        if (nombre.length() < 8){ name = nombre + "\t\t\t\t";}

        else if (nombre.length() < 16){name = nombre + "\t\t\t";}

        else if (nombre.length() < 24){name = nombre + "\t\t";}

        else if (nombre.length() < 32){name = nombre + "\t";}

        else {name = nombre;}

        if (genero.length()< 8){genre = genero + "\t";}
        else {genre = genero;}

       
        nameUnedited = nombre;
        genreUnedited = genero;
        length = duracion;
        score = calificacion;

       
        
        
        setInfo();
    }


    void setAgain(string nombre, int duracion, string genero,  float calificacion){

        setStream(nombre, duracion, genero,calificacion);

        

       
        
        
        setInfo();

    }

    void setInfo(){

        info = name + "\t"+to_string(length) + "\t\t"  + genre + "\t"  + to_string(score);

    }

    


    string getName(){return nameUnedited;}

    string getGenre(){return genreUnedited;}

    float getScore(){return score;}

    int getLength(){return length;}

    virtual string getInfoPersonal(){return "";}


    string getInfo(){return info;}

    

    virtual string getHeader(){return "Nombre\t\t\t\t\tDuración\tGénero\t\tCalificación\n\n"; }

    Streaming operator + (const Streaming& obj) {

        Streaming x;
       x.name = this->name + "\n" + obj.name;
        x. genre = this ->genre + "\n" + obj.genre;
        x.length = this ->length +  obj.length;
        x.score = this ->score + obj.score;
        x.info = this ->info  +"\n" + obj.info;

        return x;

        

        

    }



};

class Movie:public Streaming{

    public:

    float personal;

    string per;
    

    Movie(){personal = 0;per= "";}

    
        
    

    Movie(string nombre, int duracion, string genero, float calificacion)
    : Streaming(nombre,  duracion, genero, calificacion){personal = 0;}


     void setPersonal(float p){

        personal = p;
        per = info + "\t"+ to_string(personal);

    }

    float getPersonal(){return personal;}

     string getHeader(){

        if (personal != 0){

            return "Nombre\t\t\t\t\tDuración\tGénero\t\tCalificación\tPersonal\n\n";

        }

        else{return "Nombre\t\t\t\t\tDuración\tGénero\t\tCalificación\n\n";}

    }

    string getInfoPersonal(){
        if (personal != 0){return per;}

        else {return info;}
    }





   

};

class Episodio: public Streaming{

    
    public:

    int episode, season;

    

    Episodio(){

    episode = 0;
    season = 0;
    info = name + "\t" + to_string(season) + "\t" + to_string(episode) + "\t" + to_string(length)+ "\t" +genre  + "\t" + to_string(score);

    }


    Episodio(int episodio, string nombre, int temporada,int duracion, string genero,  float calificacion)
    : Streaming(nombre,  duracion, genero,calificacion){

        episode = episodio;
        season = temporada;
        
        info = name + "\t" + to_string(season) + "\t" + to_string(episode) + "\t" + to_string(length)+ "\t" +genre  + "\t" + to_string(score);
    }

    void changeInfo(int episodio, string nombre, int temporada,int duracion, string genero,  float calificacion){

        episode = episodio;
        season = temporada;
        setStream(nombre, duracion, genero,calificacion);
        info = name + "\t" + to_string(season) + "\t" + to_string(episodio) + "\t" + to_string(length)+ "\t" +genre  + "\t" + to_string(score);
        
    }

    int getEpisode(){return episode;}

    int getSeason(){ return season; }

    

     string getHeader(){return "Nombre\t\t\t\t    Temporada Episodio Duración\tGénero\t\tCalificación\n\n";}

    

        
       
};

class Series : public Streaming{

    public:


    vector <Episodio> episodes;

    
    float personal;

    string per;


    Series() { personal = 0;per = "";}

    Series(string nombre, int duracion,string genero,  float calificacion)
    : Streaming(nombre, duracion, genero,calificacion){ personal = 0;}


    void addEpisode(Episodio x){

        changeLength(x.getLength());
        

        changeScore(x.getScore());
        
        episodes.push_back(x);

        setInfo();
    }

    void changeScore(float x){

        
        score += x;
        score = score/2;
       


    }

    void changeLength(int x){
        length += x;
    }

    string getEpisodes(){

        string Episodes =  "----------------\t\t" + name + "----------------\n\n" + episodes [0].getHeader();

        for (int i = 0; i < episodes.size(); i++){

            Episodes += episodes[i].getInfo() + "\n";
        }

        return Episodes;

    }

     void setPersonal(float p){

        personal = p;
        per = info +"\t" + to_string(personal);

    }

    float getPersonal(){return personal;}

    string getHeader(){

        if (personal != 0){

            return "Nombre\t\t\t\t\tDuración\tGénero\t\tCalificación\tPersonal\n\n";

        }

        else{return "Nombre\t\t\t\t\tDuración\tGénero\t\tCalificación\n\n";}

    }


     string getInfoPersonal(){
        if (personal != 0){return per;}

        else {return info;}
    }


        


    
        
    


};

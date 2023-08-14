#include <iostream>
using namespace std;
#include "Streaming.hpp"
#include <vector>


class Servicio{

    public:

    vector <Movie *> pelis;

    vector <Series *> series;

    Streaming favorites;

    int mov, ser;


    Servicio(){

        pelis.clear();
        series.clear();

        mov = 0;
        ser = 0;
        
    }



    void addMovie(Movie *m){
        
        pelis.push_back(m);
    }

    void addSeries(Series *s){
        
        series.push_back(s);
    }

  


    string getInfo(){

        string info = favorites.getHeader();

        for (int i = 0; i < pelis.size(); i++){

            info += pelis[i]->getInfo() + "\n";

        }

         for (int i = 0; i < series.size(); i++){

            info +=series[i]->getInfo() + "\n";

        }


        return info;
    }

    string getInfo(string genero){

        string info = "";

         for (int i = 0; i < pelis.size(); i++){

             if (pelis[i] -> getGenre() == genero){

            info += pelis[i]->getInfo() + "\n";

             }

        }

         for (int i = 0; i < series.size(); i++){

            if (series[i] -> getGenre() == genero){

            info += series[i]->getInfo() + "\n";

             }

        }

        if (info == ""){return "\nNo se encontraron videos con de ese género\n";}

        else{return favorites.getHeader()+ info;}

        


    }

    string getInfo(int x,int y){

        string info = "";

        for (int i = 0; i < pelis.size(); i++){

             if (pelis[i] -> getScore() > x && pelis[i] -> getScore() < y){

            info += pelis[i]->getInfo() + "\n";

             }

        }

         for (int i = 0; i < series.size(); i++){

            if (series[i] -> getScore() > x && series[i] -> getScore() < y){

            info += series[i]->getInfo() + "\n";

             }
         }


        if (info == ""){return "\nNo se encontraron videos con de ese género\n";}

        else{return favorites.getHeader()+ info;}


    }

    string getFavorites(){return favorites.getInfo();}


    string getSeries(){

        string s = "ID\t" + series[ser]->getHeader();

        for (int i = 0; i < series.size(); i++){
            s += to_string(i+1) + "\t" + series [i] -> getInfoPersonal() + "\n";
        }


        return s;



    }

    string getSeries(int x){

        if (x< series.size()+1){return series[x-1]->getEpisodes();}

        else {return "No existe el índice";}
    }  

    string getMovies(){

         string m = "ID\t" + pelis[mov]->getHeader();

        for (int i = 0; i < pelis.size(); i++){
            m += to_string(i+1) + "\t" + pelis [i] -> getInfoPersonal() + "\n";
        }


        return m;

    }

    string getFavs(){
         string f;
        if (favorites.getLength()!= 0){  f = "----------------  Favoritos  ----------------\n\n" + 
        favorites.getHeader() + favorites.getInfo();
            }

        else{  f = "----------------  Favoritos  ----------------\n\nNo tienes Favoritos";  }
        return f;
    }


    void addPersonal(int which, int id, float cali){

        if (which== 0){

            mov = id - 1;

            pelis[mov] -> setPersonal(cali);

        }

        else{  

            ser = id - 1;

            series[ser] -> setPersonal(cali);

        }

    }

    void addFavorites(int which, int id, int id2){


        Streaming x;
        Streaming y;

        

        if (which == 0){ 

            x.setAgain(pelis[id-1]->getName(), pelis[id-1] -> getLength(),pelis[id-1] -> getGenre(),pelis[id-1] -> getScore());
             y.setAgain(pelis[id2-1]->getName(), pelis[id2-1] -> getLength(),pelis[id2-1] -> getGenre(),pelis[id2-1] -> getScore());

            favorites = x+y;
            
        }

        else{

            x.setAgain(series[id-1]->getName(), series[id-1] -> getLength(),series[id-1] -> getGenre(),series[id-1] -> getScore());
            y.setAgain(series[id2-1]->getName(), series[id2-1] -> getLength(),series[id2-1] -> getGenre(),series[id2-1] -> getScore());


            favorites = x + y;
            
        }

    }

    void addFavorites(int which, int id){


        Streaming x;

        

        if (which == 0){ 

            x.setAgain(pelis[id-1]->getName(), pelis[id-1] -> getLength(),pelis[id-1] -> getGenre(),pelis[id-1] -> getScore());

            favorites = favorites + x;
            
        }

        else{

            x.setAgain(series[id-1]->getName(), series[id-1] -> getLength(),series[id-1] -> getGenre(),series[id-1] -> getScore());

            favorites = favorites + x;
            
        }

    }


    void Menu(){

        cout << "\n----------------- NETFLIX -----------------\n" << endl;
        cout << "1. Ver Contenido" << endl;
        cout << "2. Ver Películas" << endl;
        cout << "3. Ver Series" << endl;
        cout << "4. Ver lista de Favoritos" << endl;
        cout << "5. Cerrar sesión" << endl;
    }

    void MenuSeries(){

        cout << "\n----------------- ELIJA UNA OPCIÓN -----------------\n" << endl;
        cout << "1. Agregar a Favoritos" << endl;
        cout << "2. Añadir calificación personal" << endl;
        cout << "3. Ver Episodios" << endl;
        cout << "4. Regresar al menu principal" << endl;
        


    }

    void MenuMovies(){

        cout << "\n----------------- ELIJA UNA OPCIÓN -----------------\n" << endl;
        cout << "1. Agregar a Favoritos" << endl;
        cout << "2. Añadir calificación personal" << endl;
        cout << "3. Regresar al menu principal" << endl;


    }


    void MenuF(){
        cout << "\nPresione cualquier tecla para regresar al menu principal " << endl;
    }

    void MenuT(){

         cout << "\n----------------- ELIJA UNA OPCIÓN -----------------\n" << endl;
        cout << "1. Buscar por Género" << endl;
        cout << "2. Buscar por Calificación" << endl;
        cout << "3. Regresar al menu principal" << endl;


    }


};





	


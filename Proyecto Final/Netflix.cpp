#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Servicio.hpp"
 
using namespace std;

int main(){


	vector<vector<string> >peliculas;
	vector<vector<string> >series;
	vector<string> row;
	string line, word;
	
 
	fstream file ("peliculas.csv", ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
				peliculas.push_back(row);
		}
	}
	else{
		cout<<"Could not open the file\n";
	}

	
 
	fstream file2 ("series.csv", ios::in);
	if(file2.is_open())
	{
		while(getline(file2, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
				series.push_back(row);
		}
	}
	else{
		cout<<"Could not open the file\n";
	}

	


	Movie *pelis [peliculas.size()-1];


	for (int i = 1; i < peliculas.size();i++){

		string name = peliculas[i][1];

		int duration = stoi(peliculas[i][2]);

		string genero = peliculas[i][3];

		float cali = stof(peliculas[i][4]);


		pelis [i-1] = new Movie(name,duration,genero,cali);

	}


	int s = 1;

	string serien = series[1][1];

	

	

	for (int i = 2; i < series.size();i++){

		if (serien != series [i][1] ){
			s++;

			
			serien = series [i][1];
		}
	
	}

	Series *serie [s];

	string name = series[1][1];

	int duration = stoi(series[1][5]);

	string genero = series[1][6];

	float cali = stof(series[1][7]);



	serie [0] = new Series(name,duration,genero,cali);

	


	
	s = 0;

	for (int i = 2; i < series.size();i++){

		if (name != series [i][1] ){
			s++;
			name = series [i][1];
			int duration = stoi(series[i][5]);

			string genero = series[i][6];

			float cali = stof(series[i][7]);

			serie [s] = new Series(name,duration,genero,cali);

			
		}
	
	}



	

	int episodio = stoi(series [1][2]);

	string nameE = series[1][3];

	int temporada = stoi(series [1][4]);

	int durationE  = stoi(series [1][5]);

	string generoE =  series[1][6];

	float caliE = stof(series[1][7]);

	s = 0;

	name = series [1][1];

	Episodio x(episodio, nameE, temporada,durationE,generoE,caliE);

	serie [0] -> addEpisode(x);

	


	for (int i = 2; i < series.size();i++){

		if (name != series [i][1] ){
			s++;
			name = series [i][1];
			episodio = stoi(series [i][2]);

			 nameE = series[i][3];

			temporada = stoi(series [i][4]);

			durationE  = stoi(series [i][5]);

			string generoE =  series[i][6];

			caliE = stof(series[i][7]);
;

			x.changeInfo (episodio, nameE, temporada,durationE,generoE,caliE);

			serie [s] -> addEpisode(x);

			
		}

		else{

			episodio = stoi(series [i][2]);

			string nameE = series[i][3];



			

			
			
			temporada = stoi(series [1][4]);
			

			durationE  = stoi(series [i][5]);

			string generoE =  series[i][6];

			caliE = stof(series [i][7]);

			

			
;

			x.changeInfo (episodio, nameE, temporada,durationE,generoE,caliE);

			serie [s] -> addEpisode(x);

			

		}
	
	}

	


	

	Servicio netflix;

	

	

	for (int i = 0;i < sizeof(pelis)/sizeof(pelis[0]); i++){
		netflix.addMovie(pelis[i]);
	}

	for (int i = 0;i < sizeof(serie)/sizeof(serie[0]); i++){
		netflix.addSeries(serie[i]);

	}




	int option,id,id2;
	float c;

	int min,max;
	string pause,g;



	do{

		netflix.Menu();
		cin >> option;

		switch (option){

			case 1:

				cout << "\n" << netflix.getInfo() << endl;
				netflix.MenuT();
				cin >> option;

				switch(option){

					case 1:
						cout << "Ingresar Género:" << endl;

						cin >> g;

						cout << netflix.getInfo(g) << endl;

						break;

					case 2:
						cout << "Ingresar menor Número:" << endl;

						cin >> min;

						cout << "Ingresar mayor Número:" << endl;

						cin >> max;

						cout <<netflix.getInfo(min,max) << endl;

						break;
					
					case 3:

						
						break;

					default:
						cout << "Opción inválida.";
						
						break;

					


				}
				cout  << "\n Regresando al menu principal..." << endl;
				break;

			case 2:

				cout << "\n" << netflix.getMovies() << endl;
				netflix.MenuMovies();
				cin >> option;

				switch (option){

					case 1:

						

						if (netflix.favorites.getLength() == 0){


							cout << "\n" <<"Es necesario introducir al menos 2 películas a favoritos. " << endl;
							cout <<"Introduzca ambos ID de las peliculas deseadas: " << endl;
							cin >> id;
							cin >> id2;

							netflix.addFavorites(0,id,id2);

							


						}

						else{

							cout << "\nIntroduzca el ID de la pelicula deseada: " << endl;
							cin >> id;
							netflix.addFavorites(0,id);

							

						}

						break;

					case 2:

						cout << "\nIntroduzca el ID de la pelicula deseada a modificación: " << endl;
						cin >> id;

						cout << "\nIntroduzca la nueva calificación: " << endl;

						cin >> c;

						netflix.addPersonal(0,id,c);

						break;

					case 3:

						
						break;

					default:
						cout << "Opción inválida.";
						
						break;



						
						
						

				}
				cout  << "\n Regresando al menu principal..." << endl;
				break;

				case 3: 
				cout << "\n" << netflix.getSeries() << endl;
				netflix.MenuSeries();
				cin >> option;

				switch (option){

					case 1:

						

						if (netflix.favorites.getLength() == 0){


							cout << "\n" <<"Es necesario introducir al menos 2 series a favoritos. " << endl;
							cout <<"Introduzca ambos ID de las series deseadas: " << endl;
							cin >> id;
							cin >> id2;

							netflix.addFavorites(1,id,id2);

							


						}

						else{

							cout << "\nIntroduzca el ID de la serie deseada: " << endl;
							cin >> id;
							netflix.addFavorites(1,id);

						}

						break;

					case 2:

						cout << "\nIntroduzca el ID de la serie deseada a modificación: " << endl;
						cin >> id;

						cout << "\nIntroduzca la nueva calificación: " << endl;

						cin >> c;

						netflix.addPersonal(1,id,c);

						break;

					case 3:

						cout << "\nIntroduzca el ID de la serie deseada: " << endl;
						cin >> id;

						cout << "\n" << netflix.getSeries(id) << endl;
						break;



					case 4:

						
						break;

					default:
						cout << "Opción inválida.";
						
						break;



				}

				cout  << "\n Regresando al menu principal..." << endl;
				break;
			
			case 4:

				cout << "\n" << netflix.getFavs() << endl;
				netflix.MenuF();
				cin >> pause;
				break;

			case 5:
				cout <<"\nCerrando sesión..."<< endl;
				break;
			
			default:

				cout << "Opción inválida.";
				cout  << "\n Regresando al menu principal..." << endl;
				break;

				

				





		}







	} while (option !=5);

	

	

	


	

	

	


	


return 0;

}



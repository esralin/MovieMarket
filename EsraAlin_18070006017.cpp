#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Movie{
	private:
		int id;
		string name;
		float point;
		int year;
		
	public:
		Movie(int id,float point, string name, int year){
			this->id = id;
			this->name = name;
			this->point = point;
			this->year = year;
		}
		
		Movie(){} //To be able to create non parameterized objects.
		
		
	string getName() {
        return name;
    }
    
    int getId(){
    	return id;
	}
	
	float getPoint(){
		return point;
	}
	
	int getYear(){
		return year;
	}
	
	 void setPoint(float new_point) {
        point = new_point;
    }
    
};

void printMovie(Movie movie[250]){
	for(int i = 0; i < 250 ; i++){
		cout << "ID : " << movie[i].getId() << " Point : " << movie[i].getPoint() <<  " Name : " << movie[i].getName() << " Year : " << movie[i].getYear() << endl;
    }
}


void getDetailsByID(Movie movie[250],int byID){ //OPTION 1 - Getting movie details (Movies ID are starting from 0 because of their index)
	for(int i = 0; i < 250 ; i++){
		if(movie[i].getId() == byID){
		 cout << "ID : " << movie[i].getId() << " Point : " << movie[i].getPoint() <<  " Name : " << movie[i].getName() << " Year : " << movie[i].getYear() << endl;
		
		}
	}	
}

void listYear(Movie movie[250],int range1,int range2){ //OPTION 2 - Listed by years.
	cout << "Movies listed between the years entered." << endl;
	for(int i=0 ; i< 250 ; i++){
		if((movie[i].getYear() >= range1 && movie[i].getYear() <= range2) || (movie[i].getYear() <= range1 && movie[i].getYear() >= range2)){
			 cout << " Year : " << movie[i].getYear() <<" Point : " << movie[i].getPoint() <<" ID : " << movie[i].getId() <<  " Name : " << movie[i].getName() << endl;
			 //In ýf statement,I used OR operator. Considering that users firstly could enter 1990 then 1995 OR firstly 1995 then 1990.
			 //To prevent this confusion, I coded both possibilities.
		}
	}
}

void changePoint(Movie movie[250],int id,float point){ //OPTION 3 - Changing the point of the movie.
	for(int i = 0; i < 250 ; i++){
		if(movie[i].getId() == id){
			movie[i].setPoint(point); //Changing operation is done here. 
			cout << "The point has been changed." << endl;
			getDetailsByID(movie,id);
		}
	}
}

void listLetter(Movie movie[250]){ //OPTION 4 - Getting movie details starting with the entered letter.
	string str[250]; //We should crate a string empty-array to transfer the names of the movies.
	char a;
	cout << "Which letter should the listed movies begin? Enter the first letter(Capital)." << endl;
	cin >> a;
	for(int i = 0; i < 250; i++){
		str[i] = movie[i].getName(); //Transfering is done here.
	}
	
	for(int i = 0; i < 250; i++){
		if(str[i].at(0) == a){  //Now we are searching the first letter at there.
			cout << "ID : " << movie[i].getId() << " Point : " << movie[i].getPoint() <<  " Name : " << movie[i].getName() << " Year : " << movie[i].getYear() << endl;
		}
	}
}


int main(){
	
	
	ifstream read_movies;
	
	read_movies.open("movies.txt");
	
	if(!read_movies.is_open()){
		cout << "File could not be opened." << endl;
		exit(1);
	}
	
	string line;
	int id;  //just using for counting and declarating movies. we do not have to write 'string id'
	string name;
	string point;
	string year;
	
	int counter = 0;
	Movie movie_list[250]; 

	
	while(getline(read_movies,line)){
		stringstream line_stream(line);
		
		id = counter; //determination of id's
		
		getline(line_stream, point, ';');
        getline(line_stream, name,  '(');
        getline(line_stream, year,  ')');
        
        float float_point = stof(point); //I converted point and year which were not a string before.(to reading files, every memeber should be string)
        int integer_year = stoi(year);
        
		movie_list[counter] = {id, float_point, name, integer_year};
		counter++;
		
	}

	

	
	
    int choiceNumber;
    cout << endl;
    cout << endl;
    cout << "Welcome to the Movie Market. Please select an option. " << endl;
    cout << "1 - Get movie details by ID (Starts from 0)"<< endl;
    cout << "2 - List movies between the years entered" << endl;
    cout << "3 - Change the point of a movie" << endl;
    cout << "4 - Get movie details starting with the entered letter" << endl;
    cout << "5 - Exit" << endl;
    
    
    cin >> choiceNumber;
    
    
    if(choiceNumber == 1){
    	int byID;
    	cout << "Enter ID of the movie for learning details."<< endl;
    	cin >> byID;
    	getDetailsByID(movie_list, byID);
    	main(); //To returning start menu again.
	}
	
	if(choiceNumber == 2){
		int x;
		int y;
		cout << "Enter the ranges of the movie year that you want listed. " << endl;
		cin >> x;
		cin >> y;
		listYear(movie_list,x,y);
		main();
	}
	
	if(choiceNumber == 3){
		float newPoint;
		int newID;
		printMovie(movie_list);
	    cout << "---------------------------------------------------------------------------------------------------------" << endl;
		cout << "The list of movies is as shown above.Which movie's point would you like to change? Enter the ID of the movie."<< endl;
		cin >> newID;
		cout << "Selected movie is: " ;
		getDetailsByID(movie_list, newID);
		cout << "Enter the new point."<< endl;
		cin >> newPoint;
		changePoint(movie_list,newID,newPoint);
		main();
	}
	
	if(choiceNumber == 4){
       listLetter(movie_list);
       main();
	}
	
	if(choiceNumber == 5){
		return 0;
	}
   







	read_movies.close();
	return 0;
}
		
	
	
	
	
	
	
	
	
	
	
	

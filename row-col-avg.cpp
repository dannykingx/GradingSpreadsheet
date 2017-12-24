#include <iostream>
#include <fstream>

using namespace std;

double studentScores[10][5];

// 10 students
// 5 grades



void readGrades(string fileName, int numOfExams, int numOfStudents)
{
    // ifstream --> meant to read from the file


    ifstream input;
    input.open(fileName);


    for(int i = 0; i < numOfStudents; i++)
    {
        for(int j = 0; j < numOfExams; j++)
        {

            input >> studentScores[i][j];
            cout << " " << studentScores[i][j];

            // this is where you input or read the grades from the fileName
            // and the values are then printed

        }
        cout << "\n";
    }

    input.close();
}

void getWeights(double weights[], int numOfExams)
{

double sumOfWeights = 0;

    cout << "\n";

    while(sumOfWeights != 1.0){

        // while loop to test if the sum of the exam weights in the for() loop is < 1
        // Ex: .3 + .2 + .5 = 1.0 (highest grade weight)

    for(int i = 0; i < numOfExams; i++){

    cout << "Enter the weight of column " << i << " :";
    cin >> weights[i];
    sumOfWeights += weights[i];

    // will sum weights to test statement, after it exits the for() loop
    }

    // if-statement used to continue prompting to enter the weight if the criteria is not met
    if(sumOfWeights != 1.0)
    {
        cout << "The sum of the weights is still not equal to one.";
    }
    cout << "\n";
}

}

// function used to acquire the averages of each exam (j) (ExamAvg 1, ExamAvg 2, etc.)
// avg up and down

void getAvgsOfExams(double examAvgs[], int numOfExams, int numOfStudents)
{

    for (int j = 0; j < numOfExams; j++)
    {
        for(int i = 0; i < numOfStudents; i++)
        {
            examAvgs[j] += studentScores[i][j];
        }
        examAvgs[j] = examAvgs[j]/(numOfStudents + 0.0);

        cout << "Average for exam " << (j+1) << " is " << examAvgs[j] << endl;
    }
    cout << "\n";

}

// function used to acquire how each student (i) performed on all exams as an average
// avg left to right

void getAvgsOfStudents(double studentAvgs[], double weights[], int numOfExams, int numOfStudents)
{
    for (int i = 0; i < numOfStudents; i++)
    {
        for (int j = 0; j < numOfExams; j++)
        {
            studentAvgs[i] += (studentScores[i][j])*(weights[j]);
        }

    cout << "Average for student " << (i+1) << " is " << studentAvgs[i] << endl;
    }
}

void writeFinalGrades(double examAvgs[], double studentsAvgs[], int numOfExams, int numOfStudents){

    string finalGrades = "/Users/dannyking/Desktop/finalGrades.txt";
    ofstream output;
    output.open(finalGrades);


    // will calculate each students average

    cout << "\n";

    output << "Students Averages" << endl;
    cout << "Students Averages" << endl;

    for(int i = 0; i < numOfStudents; i++)
    {

        output << studentsAvgs[i] << endl;
        cout << studentsAvgs[i] << endl;

    }

    cout << "\n";
     cout << "\n";

    output << "\n";
    output << "Exam Averages" << endl;
    cout << "Exam Averages" << endl;

    for(int j = 0; j < numOfExams; j++)
    {
        output << examAvgs[j] << endl;
        cout << examAvgs[j] << endl;
    }

    output.close();

}

int main()
{

    string fileName = "/Users/dannyking/Desktop/studentGrades.txt";
    int numOfExams = 5;
    int numOfStudents = 10;
    double examAvgs[5];
    double studentAvgs[10];
    double weights[5];

    readGrades(fileName, numOfExams, numOfStudents);
    getWeights(weights, numOfExams);
    getAvgsOfExams(examAvgs, numOfExams, numOfStudents);
    getAvgsOfStudents(studentAvgs, weights, numOfExams, numOfStudents);
    writeFinalGrades(examAvgs, studentAvgs, numOfExams, numOfStudents);

}


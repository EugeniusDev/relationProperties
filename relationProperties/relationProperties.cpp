#include <iostream>
#include <iomanip>
#include "functions.h"
#include <string>
using namespace std;
int main()
{
    string reflexivity, symmetry, transitivity;
    cout << "Enter the quantity of tops in the graph(kil\'kist\' vershyn): ";
    unsigned int size;
    cin >> size;
    //matrix creation
    int** relMatrix = new int*[size];
    for (int i = 0; i < size; i++) {
        relMatrix[i] = new int[size];
    }
    //making zeros everywhere in the matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            relMatrix[i][j] = 0;
        }
    }
    //pairs entering(forming the relation)
    cout<<"\nPairs are being entered in this way:\n(X, Y)\nIt means you need to enter X and Y values\n";
    system("pause");
    bool moreWanted = true;
    unsigned short int pairX, pairY;
    for (int i = 1; moreWanted; i++) {
        system("cls");
        //max possible is the squared size of matrix
        cout << i << " of " << size * size << " possible pairs:\n";
        if (i != 1)
            cout << "Previus pair: (" << pairX << ", " << pairY << ")\n--------------------------\n";
        cout << "Enter X value (or 0 to stop the input process): ";
        cin >> pairX;
        cout << "Enter Y value (or 0 to stop the input process): ";
        cin >> pairY;
        if (pairX > size || pairY > size) {
            cout << "Invalid input :(\n";
            return 0;
        }
        if (pairX == 0 || pairY == 0)
            moreWanted = false;
        else if(relMatrix[pairX - 1][pairY - 1] != 1){
            relMatrix[pairX - 1][pairY - 1] = 1;
        }
        else {
            i--;
            cout << "The pair is already taken. Enter another one\n";
            system("pause");
        }
    }
    system("cls");
    //showing the matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << relMatrix[i][j]<<setw(2);
        }
        cout << "\n";
    }
    //it's action time
    reflexivity = reflexivityGet(relMatrix, size);
    symmetry = symmetryGet(relMatrix, size, reflexivity);
    transitivity = transitivityGet(relMatrix, size);
    //final output info:
    cout << "\nRelation properties:\n" << reflexivity << "reflexive, "<<symmetry<<"symmetric, "<<transitivity<<"transitive\nSo, it is a relation ";
    //classification of given relation
    bool classificatable = true;
    if (reflexivity == "") {
        if (symmetry == "" && transitivity == "")
            cout << "of equivalence\n";
        else if (symmetry == "anti" && transitivity == "")
            cout << "of partly(not strict) order\n";
        else if (symmetry == "" && transitivity == "anti")
            cout << "of tolerance\n";
        else classificatable = false;
    }
    else if (reflexivity == "anti" && symmetry == "a" && transitivity == "")
        cout << "of strict order\n";
    else classificatable = false;

    if (!classificatable)
        cout << "which can\'t be classified\n";
    //deleting matrix from the heap
    for (int i = 0; i < size; i++) {
        delete[] relMatrix[i];
    }delete[] relMatrix;
}
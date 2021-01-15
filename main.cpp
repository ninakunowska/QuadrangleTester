#include <iostream>
#include <cstdlib>
using namespace std;

bool hasParallelSides(float slope_AB,float slope_BC,float slope_CD,float slope_DA){
    // posiada boki równoległę
    return (slope_AB == slope_CD || slope_DA == slope_BC);
}

bool hasSidesWithRewerseSlope(float slope_AB,float slope_BC,float slope_CD,float slope_DA){
    // posiada boki koło siebie o przeciwnym nachyleniu
    return (slope_AB == - slope_DA && slope_BC == - slope_CD || slope_CD == - slope_DA && slope_BC == - slope_AB);
}

bool hasAllParallelSides(float slope_AB,float slope_BC,float slope_CD,float slope_DA){
    // posiada wszystkie boki równoległę
    return (slope_AB == slope_CD && slope_DA == slope_BC);
}

bool hasAllSidesTheSameLength(float length_AB,float length_BC,float length_CD){
    // posiada wszystkie boki tej samej długości
    return (length_AB == length_CD && length_CD == length_BC);
}

bool hasDiagonalsTheSameLength(float length_AC,float length_BD){
    // posiada przekątne tej samej długości
    return (length_AC == length_BD);
}

string findFigure(bool hasParallelSides, bool hasSidesWithRewerseSlope, bool hasAllParallelSides, bool hasAllSidesTheSameLength, bool hasDiagonalsTheSameLength){
    if (hasParallelSides) {
        if (hasAllParallelSides) {
            if (hasAllSidesTheSameLength) {
                return hasDiagonalsTheSameLength ? "kwadrat" : "romb";
            } else{
                return hasDiagonalsTheSameLength ? "prostokąt" : "równoległobok";
            }
        } else
            return "trapez";
    } else {
        return hasSidesWithRewerseSlope ? "deltoid" :  "czworokąt dowolny";
    }
}


int main() {
    float punkty[4][2];
    cout<< "Podaj kolejno współrzędne wierzchołków czworokąta:"<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=0; j<2; j++){
            if(j%2==0) {
                cout<< "podaj współrzędną x punktu "<<i+1<<": ";
                cin>>punkty[i][j];
            }else{
                cout<< "podaj współrzędną y punktu "<<i+1<<": ";
                cin>>punkty[i][j];
            }

        }
    }

    float x1= punkty[0][0];
    float y1= punkty[0][1];
    float x2= punkty[1][0];
    float y2= punkty[1][1];
    float x3= punkty[2][0];
    float y3= punkty[2][1];
    float x4= punkty[3][0];
    float y4= punkty[3][1];

    if ((x1 == x2 && x2 == x3) || (x2 == x3 && x3 == x4) || (x3 == x4 && x4 == x1) || (y1 == y2 && y2 == y3) || (y2 == y3 && y3 == y4) || (y3 == y4 && y4 == y1)) {
        cout<< "Błędne dane"<<endl;
        cout<< "Podane punkty nie są wierzchołkami czworokąta."<<endl;
        return 0;
    }

    cout<<x1<<"\t"<<y1<<endl<<x2<<"\t"<<y2<<endl<<x3<<"\t"<<y3<<endl<<x4<<"\t"<<y4<<endl;

    cout<<endl;

    float length_AB = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    cout<<"dlugość AB= "<<length_AB<<endl;
    float length_BC = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    cout<<"dlugość BC= "<<length_BC<<endl;
    float length_CD = sqrt((x4-x3)*(x4-x3)+(y4-y3)*(y4-y3));
    cout<<"dlugość CD= "<<length_CD<<endl;
    float length_DA = sqrt((x4-x1)*(x4-x1)+(y4-y1)*(y4-y1));
    cout<<"dlugość DA= "<<length_DA<<endl;

    cout<<endl;

    float slope_AB = (y2-y1)/(x2-x1);
    cout<<"nachylenie AB= "<<slope_AB<<endl;
    float slope_BC = (y3-y2)/(x3-x2);
    cout<<"nachylenie BC= "<<slope_BC<<endl;
    float slope_CD = (y4-y3)/(x4-x3);
    cout<<"nachylenie CD= "<<slope_CD<<endl;
    float slope_DA = (y4-y1)/(x4-x1);
    cout<<"nachylenie DA= "<<slope_DA<<endl;

    cout<<endl;

    float length_AC = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
    cout<<"dlugość przekątnej AC= "<<length_AC<<endl;
    float length_BD = sqrt((x4-x2)*(x4-x2)+(y4-y2)*(y4-y2));
    cout<<"dlugość przekątnej BD= "<<length_BD<<endl;

    cout<<endl;

    bool hasParallelSidesVar = hasParallelSides(slope_AB,slope_BC,slope_CD,slope_DA);
    bool hasSidesWithRewerseSlopeVar = hasSidesWithRewerseSlope(slope_AB, slope_BC, slope_CD, slope_DA);
    bool hasAllParallelSidesVar = hasAllParallelSides(slope_AB,slope_BC,slope_CD,slope_DA);
    bool hasAllSidesTheSameLengthVar = hasAllSidesTheSameLength(length_AB,length_BC,length_CD);
    bool hasDiagonalsTheSameLengthVar = hasDiagonalsTheSameLength(length_AC,length_BD);

    cout<< "min 2 boki równoległe: "<< hasParallelSidesVar << endl;
    cout << "boki koło siebie o przeciwnym nachyleniu: " << hasSidesWithRewerseSlopeVar << endl;
    cout<< "wszystkie boki równoległe: "<< hasAllParallelSidesVar << endl;
    cout<< "wszystkie boki tej samej długości: "<< hasAllSidesTheSameLengthVar << endl;
    cout<< "przekątne równej długości: "<< hasDiagonalsTheSameLengthVar << endl;

    cout<<endl;
    string figure;
    figure = findFigure(hasParallelSidesVar, hasSidesWithRewerseSlopeVar, hasAllParallelSidesVar, hasAllSidesTheSameLengthVar, hasDiagonalsTheSameLengthVar);

    cout<<"figura to: " << figure;

    cout<<endl;

    return 0;
}

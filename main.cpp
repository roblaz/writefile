#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>



struct Point{
    float x;
    float y;
    char Name;
};

float distance(Point A, Point B); // return distance between point A and B (use Pifagor's Theorem)
float perimeter(Point Array[4]); // return distance perimeter usind function distance 4 times
float area(Point Array[4]);  // return area using Gauss's area formula or use Geron formaula for two triangles ABC + ACD

float deter(Point A, Point B);

//float cross(Point Array[4]);

//void bound(Point Array[], int len, Point Box[]);

void vSaveResult(QString pStringResult);

QString printQuad(Point Arr[4]); // and also to QString

QString strSaveResult[15];
int iCurrentSave = 0;
//QString strSaveResult[COUNTSAVERESULT];

int main()
{
    QString qsRetVal;
    float perim,ar;

    //First point

    Point quadOne[4];

    quadOne[0].Name='A';
    quadOne[0].x=0.0;
    quadOne[0].y=0.0;

    quadOne[1].Name='B';
    quadOne[1].x=4.0;
    quadOne[1].y=0.0;

    quadOne[2].Name='C';
    quadOne[2].x=4.0;
    quadOne[2].y=4.0;

    quadOne[3].Name='D';
    quadOne[3].x=0.0;
    quadOne[3].y=4.0;

    qsRetVal = printQuad(quadOne);
    qDebug() << qsRetVal;
    vSaveResult(qsRetVal);

    qsRetVal = "Have perimeter %1 and area %2";
    perim = perimeter(quadOne);
    ar = area(quadOne);
    qsRetVal = qsRetVal.arg(perim,0,'f',2).arg(ar,0,'f',3);
    qDebug() << qsRetVal;
    qsRetVal += "\n";
    vSaveResult(qsRetVal);

    //Second point
    Point E={-10.0,-10.0,'E'};
    Point F={ 10.0,-10.0,'F'};
    Point G={ 10.0, 10.0,'G'};
    Point H={-10.0, 10.0,'H'};
    Point QE[4]={E, F, G, H};

    qsRetVal = printQuad(QE);
    qDebug() << qsRetVal;
    vSaveResult(qsRetVal);

    perim = perimeter(QE);
    ar = area(QE);
    qsRetVal = "Have perimeter %1 and area %2";
    qsRetVal = qsRetVal.arg(perim,0,'f',2).arg(ar,0,'f',3);
    qDebug() << qsRetVal;
    qsRetVal += "\n";
    vSaveResult(qsRetVal);

    //Third point
    Point A={-9.0,-5.8,'a'};
    Point B={-6.2,9.1,'b'};
    Point C={-8.4,6.8,'c'};
    Point D={-2.9,-0.3,'d'};

    Point Q1[4]={A, B, C, D};

    qsRetVal = printQuad(Q1);
    qDebug() << qsRetVal;
    vSaveResult(qsRetVal);

    perim = perimeter(Q1);
    ar = area(Q1);
    qsRetVal = "Have perimeter %1 and area %2";
    qsRetVal = qsRetVal.arg(perim,0,'f',2).arg(ar,0,'f',3);
    qDebug() << qsRetVal;
    qsRetVal += "\n";
    vSaveResult(qsRetVal);

    //Fourth point
    Point Q2[4]={D, C, B, A};

    qsRetVal = printQuad(Q2);
    qDebug() << qsRetVal;
    vSaveResult(qsRetVal);

    perim = perimeter(Q2);
    ar = area(Q2);
    qsRetVal = "Have perimeter %1 and area %2";
    qsRetVal = qsRetVal.arg(perim,0,'f',2).arg(ar,0,'f',3);
    qDebug() << qsRetVal;
    qsRetVal += "\n";
    vSaveResult(qsRetVal);

    //Fifth point
    A = {2.0, 5.0,'a'};
    B = {6.0, 7.0,'b'};
    C = {9.0, 4.0,'c'};
    D = {3.0, 3.0,'d'};

    Point Q3[4]={A, B, C, D};
    qsRetVal = printQuad(Q3);
    qDebug() << qsRetVal;
    vSaveResult(qsRetVal);

    perim = perimeter(Q3);
    ar = area(Q3);
    //float c = cross(Q3);
    qsRetVal = "Have perimeter %1 and area %2";
    qsRetVal = qsRetVal.arg(perim,0,'f',2).arg(ar,0,'f',3);
    qDebug() << qsRetVal;
    qsRetVal += "\n";
    vSaveResult(qsRetVal);

    //Sixth point
    Point Q4[4]={A, C, B, D};

    qsRetVal = printQuad(Q4);
    qDebug() << qsRetVal;
    vSaveResult(qsRetVal);

    perim = perimeter(Q4);
    ar = area(Q4);
    //c = cross(Q4);
    qsRetVal = "Have perimeter %1 and area %2";
    qsRetVal = qsRetVal.arg(perim,0,'f',2).arg(ar,0,'f',3);
    qDebug() << qsRetVal;
    qsRetVal += "\n";
    vSaveResult(qsRetVal);

    QFile qf("SaveResult.txt");
    if (qf.open(QFile::WriteOnly | QFile::Truncate)) {
          QTextStream out(&qf);

          for (int i=0; i < iCurrentSave; i++) {
              out << strSaveResult[i];
              out << endl;
          }
      }
    qf.close();

}

QString printQuad(Point Arr[4])
{
    QString qsRetVal = "Quadrilateral with points: ";
    QString qsTemp;
    Point curPoint;
    for (int i=0; i<4; i++){
        qsTemp = "%1[%2;%3] ";
        curPoint = Arr[i];
        qsTemp=qsTemp.arg(curPoint.Name).arg(curPoint.x).arg(curPoint.y);
        qsRetVal.append(qsTemp);
    }
    return qsRetVal;
}

float distance(Point A, Point B)
{
    return sqrt( (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) );
}

float perimeter(Point Array[4])
{
    Point A[5];
    int i=0;

    for (; i<4; i++)
        A[i]=Array[i];

    A[i]=Array[0];

    float ret=0;
    for (i=0; i<4; i++)
        ret += distance(A[i],A[i+1]);

    return ret;
}

float deter(Point A, Point B)
{
    return ((A.x*B.y) - (A.y*B.x));
}

float area(Point Array[4])
{
    Point A[5];
    int i=0;

    for (; i<4; i++)
        A[i]=Array[i];
    A[i]=Array[0];

    float ret = 0;
    float det=0;
    QString qsTemp;

    for (i=0; i<4; i++) {
        det = deter(A[i],A[i+1]);
        qsTemp= "Deter for [%1,%2] : [%3,%4] is %5";
        qsTemp= qsTemp.arg(A[i].x).arg(A[i].y).arg(A[i+1].x).arg(A[i+1].y).arg(det);
        qDebug() << qsTemp;
        ret += det;
    }
    return fabs((float)(ret / 2.0));
}

/*
float cross(Point Array[4])
{
    Point A[5];
    int i=0;

    for (; i < 4; i++)
        A[i] = Array[i];

    A[i] = Array[0];

    //Point Z={0.0, 0.0,'z'};
    float det=0;
    QString qsTemp;

    for (i=0; i<4; i++) {
        det = distance(A[i], A[i+1]);
        qsTemp= "distance for [%1,%2] : [%3,%4] is %5";
        qsTemp= qsTemp.arg(A[i].x).arg(A[i].y).arg(A[i+1].x).arg(A[i+1].y).arg(det);
        qDebug() << qsTemp;
    }
    return det;
}


void bound(Point Array[], int len, Point Box[])
{
    float top, bottom, left, rigt;
    Point CP = Array[0]; // curPoint;

    top = CP.y;
    bottom = CP.y;
    left = CP.x;
    rigt = CP.x;

    for (int i=1; i<len; i++) {
        CP = Array[i];

        if (top<CP.y) top=CP.y;
        if (bottom>CP.y) bottom=CP.y;

        if (left>CP.x) left=CP.x;
        if (rigt<CP.x) rigt=CP.x;

    }
    Box[0].x=left;
    Box[0].y=top;

    Box[1].x=rigt;
    Box[1].y=bottom;
}
*/

void vSaveResult(QString pStringResult) {
    //if (pCurrentPosition > COUNTSAVERESULT - 2) {

    if (iCurrentSave > 15 - 2) {

        qDebug() << "Array by save result is full";

        return;
    }

    strSaveResult[iCurrentSave++] = pStringResult;

}


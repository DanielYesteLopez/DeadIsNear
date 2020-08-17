//
// Created by danielyeste on 1/8/20.
//

#ifndef DEADISNEAR_VECTOR2D_H
#define DEADISNEAR_VECTOR2D_H
class Vector2D{
public:
    float x;
    float y;

    Vector2D(float x,float y);
    Vector2D();

    Vector2D& Add(const Vector2D& vec);
    Vector2D& Sub(const Vector2D& vec);
    Vector2D& Mul(const Vector2D& vec);
    Vector2D& Div(const Vector2D& vec);
    friend Vector2D& operator+= (Vector2D& v1,Vector2D& v2);
    friend Vector2D& operator-= (Vector2D& v1,Vector2D& v2);
    friend Vector2D& operator*= (Vector2D& v1,Vector2D& v2);
    friend Vector2D& operator/= (Vector2D& v1,Vector2D& v2);
    Vector2D& operator+= (const Vector2D& vec);
    Vector2D& operator-= (const Vector2D& vec);
    Vector2D& operator*= (const Vector2D& vec);
    Vector2D& operator/= (const Vector2D& vec);

    Vector2D& operator*(const int& i);
    Vector2D& Zero();


};
#endif //DEADISNEAR_VECTOR2D_H

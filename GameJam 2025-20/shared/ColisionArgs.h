#pragma once
using namespace System;
using namespace System::Drawing;

public ref class ColisionArgs {
public:
    int scoring;
    Color color;
    ColisionArgs(int s, Color c) { scoring = s; color = c; }
};
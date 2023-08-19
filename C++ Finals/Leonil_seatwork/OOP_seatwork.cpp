#include <iostream>

using namespace std;

class block
{
private:
    int width;
    int length;
    int height;
    int volume;
    int surfaceArea;

public:
    block(int arr[])
    {
        this->width = arr[0];
        this->length = arr[1];
        this->height = arr[2];
        this->volume = (width * length * height);
        this->surfaceArea = ((2 * (length * width)) + (2 * (length * height)) + (2 * (height * width)));

        cout << "Block width: " << getWidth() << endl;
        cout << "Block length: " << getLength() << endl;
        cout << "Block height: " << getHeight() << endl;
        cout << "Block volume: " << getVolume() << endl;
        cout << "Block Surface Area: " << getSurfaceArea() << endl;
    }

    int getWidth()
    {
        return width;
    }
    int getLength()
    {
        return length;
    }
    int getHeight()
    {
        return height;
    }
    int getVolume()
    {
        return volume;
    }
    int getSurfaceArea()
    {
        return surfaceArea;
    }
};

int main()
{
    int width, length, height;
    cout << "Enter width: ";
    cin >> width;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter height: ";
    cin >> height;
    int arr[] = {width, length, height};
    block myblock(arr);
}
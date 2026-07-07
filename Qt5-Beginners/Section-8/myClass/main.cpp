#include <QCoreApplication>
#include "animal.h";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    animal cat;
    cat.speak("meow");

    animal dog;
    dog.speak("bark");

    animal bird;
    bird.speak("chirp");

    return QCoreApplication::exec();
}

#ifndef BOITENOIRE_H
#define BOITENOIRE_H

//SRTUCTURES
typedef struct Frame{
    long timestamp;
    float vitesse;
    float temperature;
    struct Frame *suivant;
}Frame;


typedef struct BoiteNoire{
        struct Frame *debut;
        int nb_frames;

}BoiteNoire;


//protypes des fonctions

void add_frame(BoiteNoire *b, float v, float t);
void delete_first(BoiteNoire*b);
void dump_memory(BoiteNoire *b);
void crash_analyse();
#endif

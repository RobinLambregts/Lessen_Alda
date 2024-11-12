//
// Created by robin on 12/11/2024.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::string story = "Tafel tafelkleed In een klein dorp, gelegen aan de rand van een groot, donker bos, leefde een jongen genaamd Pieter. "
                    "Pieter hield van de natuur en bracht veel tijd door in het bos, waar hij allerlei dieren observeerde. "
                    "Het bos was magisch en veranderde met elk seizoen. In de lente bloeiden de bloemen in de meest levendige kleuren, "
                    "en in de zomer zorgden de hoge bomen voor verkoelende schaduw. In de herfst kleurden de bladeren felgeel, rood en oranje, "
                    "terwijl in de winter een dikke laag sneeuw het landschap bedekte.\n\n"
                    "Op een dag, tijdens een van zijn wandelingen, vond Pieter een oude kaart. De kaart was bedekt met vlekken, "
                    "maar hij kon er toch een route op zien die diep het bos in leidde. Pieter was nieuwsgierig en besloot de kaart te volgen. "
                    "Hij liep urenlang, klom over rotsen en stapte over beekjes, totdat hij bij een open plek in het bos kwam. "
                    "In het midden van de open plek stond een groot, oud kasteel, dat half verborgen was door klimop en struiken.\n\n"
                    "Het kasteel was mysterieus en leek verlaten. Pieter ging voorzichtig naar binnen. De gangen waren donker, "
                    "en het enige geluid dat hij hoorde was het geritsel van bladeren buiten en het zachte getik van druppels die uit het plafond vielen. "
                    "Pieter liep door de gangen en ontdekte een kamer met een grote spiegel. Toen hij in de spiegel keek, zag hij iets vreemds: "
                    "zijn spiegelbeeld leek een eigen leven te leiden! Het spiegelbeeld glimlachte naar hem en wenkte hem om dichterbij te komen. "
                    "Pieter voelde een mix van nieuwsgierigheid en angst.\n\n"
                    "De jongen besloot zijn angst opzij te zetten en stapte dichter naar de spiegel. Plotseling voelde hij een lichte trek en "
                    "werd hij door de spiegel getrokken. Aan de andere kant bevond hij zich in een andere wereld, een magische wereld vol met wezens "
                    "die hij nog nooit eerder had gezien. De lucht was lichter dan in zijn eigen wereld, en overal om hem heen waren er bloemen die leken te gloeien. "
                    "Terwijl hij verder liep, ontdekte hij dat deze wereld haar eigen geheimen had, net zoals het oude kasteel en het donkere bos.";

struct Node {
    std::unordered_map<char, Node*> children{};
    bool stop;
};

int tracker = 0;

void insertLetter(Node* node, char letter) {
    letter = std::tolower(letter);
    std::cout << "insert letters: " << story[tracker];
    if (node == nullptr) {return;}
    if (std::string{" ,.!?"}.contains(letter)) {
        Node* endNode = new Node{};
        node->children.insert(std::pair<char, Node*>('*', endNode));
        node->stop = true;
        return;
    }
    std::cout << "     -succes-    " << std::endl;
    std::unordered_map<char, Node*> &children = node->children;
    if(!children.contains(letter)) {
        tracker++;
        auto newNode = new Node{};
        children.insert(std::pair<char, Node*>(letter, newNode));
        insertLetter(newNode, story[tracker]);
    }
    else {
        tracker++;
        insertLetter(children[letter], story[tracker]);
    }
}

int main() {
    Node* root = new Node();
    while(story[tracker] != '\0') {
        std::cout << std::endl;
        std::cout << "1e letters: " << story[tracker] << '\n';
        insertLetter(root, story[tracker]);
        tracker++;
    }
    return 0;
}
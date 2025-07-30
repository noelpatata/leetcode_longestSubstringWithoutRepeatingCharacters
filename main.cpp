#include <iostream>

int lengthOfLongestSubstring(const std::string& s) {
    int lastIndex[128] = {0}; //array de 128 inicializado en 0 (es de 128 porque C++ usa ASCII para codificar los carácteres.
    // Como ASCII guarda cada carácter en 7 bits, y un bit son 0 y 1 (dos posibles valores), para obtener el número de valores posibles sólo
    // hay que hacer 2⁷=128 para saber que el número de valores posibles es 128. Todo esto significa que C++, realmente no guarda 'A',
    // si no que guarda el número 65, cuando lo imprimimos, como sabe que es un char, lo convierte gracias a la codificación ASCII.
    // De esta forma, aunque me pueda venir un string de 50.000 carácteres (como bien indica el ejercicio), sólo quiero valores únicos,
    // por tanto, como máximo guardaré 128 valores (guarda el valor ASCII)).
    int maxLen = 0;
    int start = 0;

    for (int end = 0; end < s.length(); ++end) {

        start = std::max(start, lastIndex[s[end]]); // comparar el indice que simboliza el inicio del tramo con el
        // indice del carácter encontrado (en caso de que se encuentre), para empezar a leer en la repetición más reciente.
        maxLen = std::max(maxLen, end - start + 1); // comparar maxLen anterior con el actual tramo leído (desde start, hasta end)
        // (se suma 1 porque si leo el carácter en la posición 0, cuento un carácter leído). 
        lastIndex[s[end]] = end + 1; // guardo el valor como leído en el array (ya que está inicializado con 0's).
    }

    return maxLen;
}


int main() {
    std::string arr [4] = {"abcabcbb"};
    for(int i = 0; i < 4; i++){
        std::string input = arr[i];
        if(input.length() <= 0){ continue; }

        int result = lengthOfLongestSubstring(input);
        std::cout << "Length of input: " << input.length() << std::endl;
        std::cout << "Length of the longest substring without repeating characters: " << result << std::endl;
    }

    
    return 0;
}
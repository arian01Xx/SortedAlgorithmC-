#include <iostream>

template <typename T>
class Ordenador{
public:
	virtual void ordenar(std::vector<T>& arr)=0;
	void imprimir(std::vector<T>& lista){
		std::cout<<"[";
		int i=0;
		for(T elem: lista){
			std::cout<<elem<<(i<lista.size() - 1 ? ", " : ""):
			i++;
		}
		std::cout<<"]"<<std::endl;
	}
};

template <typename T>
class OrdenadorBubbleSort: public Ordenador<T>{
public:
	void ordenar(std::vector<T>& lista){
		for(int i=0; i<lista.size(); i++){
			for(int j=1; j<lista.size()-i; j++){
				if(lista[j]<lista[j-1]){
					T temp=lista[j];
					lista[j]=lista[j-1];
					lista[j-1]=temp;
				}
			}
		}
	}
};

template <typename T>
class OrdenadorSelectionSort: public: Ordenador<T>{
public:
	void ordenar(std::vector<T>& lista){
		for(int i=0; i<lista.size(); i++){
			int idx=i;
			for(int j=i+1; j<lista.size(); j++){
				if(lista[j]<lista[idx]){
					idx=j;
				}
			}
			T temp=lista[idx];
			lista[idx]=lista[i];
			lista[i]=temp;
		}
	}
};

template <typename T>
class OrdenadorInsertionSort: public: Ordenador<T>{
public:
	void ordenar(std::vector<T>& lista){
		for(int i=0; i<lista.size(); i++){
			bool insertado=true;
			for(int j=0; j<i && !insertado; j++){
				if(lista[j] >= lista[i]){
					T temp=lista[i];
					for(int k=i; k>=j+1; k--){
						lista[k]=lista[k-1];
					}
					lista[j]=temp;
					insertado=true;
				}
			}
		}
	}
};

int main(){

	return 0;
}
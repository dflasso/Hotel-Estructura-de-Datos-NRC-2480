#ifndef NODO_H
#define NODO_H
class Nodo
{
	private:
		char espaniol[50];
		char ingles[50];
		Nodo* siguienteDireccion;
	public:
		void setEspaniol(char[]);
		char* getEspaniol();
		void setIngles(char[]);
		char* getIngles();
		void setSiguienteDireccion(Nodo*);
		Nodo* getSiguienteDireccion();
};

void Nodo::setEspaniol(char espaniol_[50])
{
	strcpy(espaniol,espaniol_);
}
char* Nodo::getEspaniol()
{
	return espaniol; 
}

void Nodo::setIngles(char ingles_[50])
{
	strcpy(ingles,ingles_);
}
char* Nodo::getIngles()
{
	return ingles; 
}

void Nodo::setSiguienteDireccion(Nodo* siguienteDireccion_)
{
	siguienteDireccion=siguienteDireccion_;
}

Nodo* Nodo::getSiguienteDireccion()
{
	return siguienteDireccion;
}

#endif

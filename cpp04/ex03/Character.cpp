#include "Character.hpp"

static void delete_array(AMateria ***arr);
static void array_append(AMateria ***arr, AMateria* element);

Character::Character(std::string name) : name(name) {
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
	this->floor = NULL;
}

Character::Character(Character const & src) : name(src.name) {
	this->floor = NULL;
	for (int i = 0; i < 4; i++)
		if (src.inventory[i] != NULL)
			this->inventory[i] = src.inventory[i]->clone();
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL) {
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	delete_array(&(this->floor));
	// std::cout << this->name << ": I die now" << std::endl;
}

Character &	Character::operator=(Character const & rhs) {
	this->name = rhs.name;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL) {
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		if (rhs.inventory[i] != NULL)
			this->inventory[i] = rhs.inventory[i]->clone();
	}
	delete_array(&(this->floor));
	
	return (*this);
}

std::string const & Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	int i = 0;
	for (; i < 4; i++) {
		if (this->inventory[i] != NULL)
			continue ;
		this->inventory[i] = m;
		break ;
	}
	if (i == 4)
		array_append(&(this->floor), m);
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4)
		return;
	array_append(&(this->floor), this->inventory[idx]);
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || this->inventory[idx] == NULL)
		return;
	this->inventory[idx]->use(target);
}

static void delete_array(AMateria ***arr) {
	if (*arr == NULL)
		return;
	int i = 0;
	while ((*arr)[i] != NULL) {
		delete (*arr)[i];
		i++;
	}
	delete[] *arr;
	*arr = NULL;
}

static void array_append(AMateria ***arr, AMateria* element) {
	if (element == NULL)
		return;
	int size = 0;
	while (*arr != NULL && (*arr)[size] != NULL)
		size++;
	AMateria **new_arr = new AMateria*[size + 2];
	new_arr[size + 1] = NULL;
	new_arr[size] = element;
	while (size-- > 0)
		new_arr[size] = (*arr)[size];
	if (*arr != NULL)
		delete[] *arr;
	*arr = new_arr;
}

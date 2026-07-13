# level14

## Contexte

Le home de `level14` est vide.

## Recherche

Comme pour le niveau précédent, il n'y a aucun fichier à exploiter.

On cherche donc du côté du programme `getflag`.

En l'analysant avec **Ghidra**, on remarque qu'il vérifie lui aussi l'UID avant d'afficher le flag.

## Vulnérabilité


Il n'y a pas réellement de vulnérabilité à exploiter.

Le binaire contient lui-même la fonction permettant de déchiffrer les différents flags. En l'analysant, il est possible de réutiliser cette fonction sans avoir à contourner les vérifications effectuées par `getflag`.

## Exploitation

On décompile le programme `getflag` avec **Ghidra**.

On repère la fonction `ft_des()`, qui sert à déchiffrer les différents flags, puis on copie son code dans un fichier C.

Il ne reste plus qu'à écrire un petit `main` qui appelle cette fonction avec la valeur utilisée lorsque `getflag` est exécuté par `flag14` :

```c
int main() {
    char* flag = ft_des("g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|");
    printf("flag: %s", flag);

    return 0;
}
```

On compile puis on exécute le programme :

```bash
cc crack_getflag.c
./a.out
```

Le programme affiche directement le flag :

```
7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
```

On peut ensuite l'utiliser pour se connecter à `flag14` qui nous prompt avec un message de félicitations !

## Ressources

- Ghidra
- Reverse engineering
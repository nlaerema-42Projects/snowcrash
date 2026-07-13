# level13

## Contexte

On trouve un exécutable `level13` dans le home de `level13`.

## Recherche

On lance le programme :

```bash
./level13
```

Le programme affiche :

```text
UID 2013 started us but we we expect 4242
```

En analysant le binaire, on remarque qu'il vérifie l'UID de l'utilisateur avec `getuid()`.

## Vulnérabilité

Le programme refuse de fonctionner si l'UID n'est pas `4242`.

Cette vérification est faite côté client et peut être contournée.

Il suffit de modifier la valeur de retour de `getuid()` pour faire croire au programme que l'on possède le bon UID.

## Exploitation

TODO

On lance le programme avec `gdb` :

```bash
gdb ./level13
```

On place un point d'arrêt après l'appel à `getuid()`, puis on modifie la valeur de retour :

```gdb
break main
run
...
set $eax=4242
continue
```

Le programme pense alors être exécuté par `flag13` et affiche le mot de passe.

On utilise ensuite ce mot de passe pour se connecter à `flag13` et lancer :

```bash
getflag
```

Résultat :

```text
2A31L79asukciNyi8uppkEuSx
```

## Ressources

- `getuid()`
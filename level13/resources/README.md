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

On copie le binaire et on modifie directement les octets correspondant à l'UID vérifié.

Le programme compare l'UID de l'utilisateur avec `4242`. En remplaçant cette valeur par la nôtre dans le binaire, le programme acceptera de s'exécuter.

On utilise `perl` pour effectuer le patch binaire :

```bash
cp ./level13 /tmp/level13
uid=$(id -u)
# Remplace les octets de l'UID 4242 par notre UID
perl -i -0777 -pe "s/\x92\x10/\x$(printf '%02x' $uid)/g" /tmp/level13
/tmp/level13
```

Le programme affiche le mot de passe. On l'utilise ensuite pour se connecter à `flag13` et lancer `getflag` :

```bash
getflag
```

Résultat :

```text
2A31L79asukciNyi8uppkEuSx
```

## Ressources

- `getuid()`
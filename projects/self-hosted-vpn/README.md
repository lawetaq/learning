# Self-Hosted VPN on VPS

## Goal

Set up a personal self-hosted VPN on a rented VPS and connect both a Linux desktop and an iPhone.

This project was completed as part of my infrastructure and DevOps learning path.

## Environment

### Server

* VPS
* Debian 12
* SSH access

### Client devices

* Linux desktop: Nobara 43 KDE
* iPhone

## Initial Manual Approach

The first attempt was a manual VPN deployment using:

* Xray
* VLESS
* Reality
* Hiddify
* Nekoray / NekoBox

### What was done

* Rented and configured a VPS.
* Connected to the server via SSH.
* Installed Xray.
* Generated VLESS + Reality configuration files.
* Created multiple client profiles.
* Tested client profile imports in Hiddify and Nekoray.

### Problems encountered

* Hiddify rejected generated profiles because of malformed Reality public key data.
* Manual profile editing was required.
* Hiddify on Linux had background core failures.
* System Proxy mode connected, but traffic was not routed correctly.
* Tun Mode either failed to start or broke connectivity.
* Nekoray could establish VLESS connections and pass URL tests, but system-wide routing still did not work reliably.

### Lessons from the manual attempt

* A successful VPN connection test does not always mean that system traffic is routed correctly.
* Linux VPN clients can behave differently even with a valid server-side configuration.
* VLESS + Reality requires careful validation of generated configuration values.
* Client-side routing issues can take more time to debug than the actual server deployment.

## Final Working Solution

The VPS was reinstalled with a clean Debian 12 installation.

Instead of continuing manual Xray troubleshooting, I switched to AmneziaVPN.

### Deployment process

* Installed the AmneziaVPN client on Linux.
* Added the VPS using server credentials.
* Chose automatic installation.
* AmneziaVPN automatically deployed AmneziaWG on the VPS.
* Generated client configuration automatically.
* Connected an iPhone using a QR code.

### Result

Successfully connected:

* Linux desktop
* iPhone

Verification:

* External IP changed to the VPS IP.
* Web browsing worked normally.
* YouTube and other services were accessible.
* VPN tunnel operated correctly.

## Technologies Used

### Server and system administration

* VPS
* Debian 12
* SSH

### Manual attempt

* Xray
* VLESS
* Reality
* Hiddify
* Nekoray / NekoBox

### Final setup

* AmneziaVPN
* AmneziaWG

## Key Takeaways

* Self-hosting a VPN on a VPS is practical even for a beginner.
* SSH and basic VPS management are important infrastructure skills.
* Manual Xray deployments are useful for learning, but may require extensive debugging.
* Client-side routing issues can be difficult and time-consuming.
* AmneziaVPN provided a faster and more reliable path to a working self-hosted VPN.
* A working solution is sometimes more valuable than spending too much time debugging a fragile setup.

## Security Notes

This repository does not include:

* server IP addresses;
* passwords;
* private keys;
* VPN client configuration files;
* QR codes;
* tokens or secrets.

Only a sanitized technical summary is stored here.

## Future Improvements

Possible future improvements:

* learn more about WireGuard / AmneziaWG internals;
* document basic VPS hardening steps;
* configure a non-root SSH user;
* review firewall rules;
* compare AmneziaWG with manual WireGuard setup;
* later revisit VLESS + Reality after learning more about networking and routing.

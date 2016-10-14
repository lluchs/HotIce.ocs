# Use `make decrypt PASSWORD=<obvious password>` to decrypt. Ignore errors from
# circular dependencies.

files := \
	Sound.ocg/vietnammusic1.ogg \
	Sound.ocg/vietnammusic2.ogg \
	Sound.ocg/vietnammusic3.ogg \

decrypt: $(files)
encrypt: $(files:Sound.ocg/%=Sound.ocg/.%.gpg)

%: .%.gpg
	gpg --batch --yes --passphrase $(PASSWORD) --output $@ --decrypt $<

.%.gpg: %
	gpg --batch --yes --passphrase $(PASSWORD) --output $@ --symmetric $<

.PHONY: encrypt decrypt

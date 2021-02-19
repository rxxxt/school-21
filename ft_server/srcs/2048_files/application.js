// Wait till the browser is ready to render the game (avoids glitches)
window.requestAnimationFrame(function () {
  if (typeof window.PokiSDK !== "undefined") {
    PokiSDK.init()
      .then(function () {
        PokiSDK.gameLoadingStart();
        PokiSDK.gameLoadingProgress({ percentageDone: 1 });
        PokiSDK.gameLoadingFinished();

        runApplication();
      })
      .catch(() => {
        runApplication();
      });
  } else {
    runApplication();
  }
});

function runApplication() {
  new GameManager(4, KeyboardInputManager, HTMLActuator, LocalStorageManager);

  // TODO: This code is in need of a refactor (along with the rest)
  var storage = new LocalStorageManager();
  var cookieNotice = document.querySelector(".cookie-notice");
  var cookieNoticeClose = document.querySelector(
    ".cookie-notice-dismiss-button"
  );

  if (storage.getCookieNoticeClosed()) {
    cookieNotice.parentNode.removeChild(cookieNotice);
  } else {
    cookieNoticeClose.addEventListener("click", function () {
      cookieNotice.parentNode.removeChild(cookieNotice);
      storage.setCookieNoticeClosed(true);
      if (typeof gtag !== undefined) {
        gtag("event", "closed", {
          event_category: "cookie-notice",
        });
      }
    });
  }

  var howToPlayLink = document.querySelector(".how-to-play-link");
  var gameExplanation = document.querySelector(".game-explanation");

  if (howToPlayLink && gameExplanation) {
    howToPlayLink.addEventListener("click", function () {
      gameExplanation.scrollIntoView({ behavior: "smooth", block: "center" });
      gameExplanation.addEventListener("animationend", function () {
        gameExplanation.classList.remove("game-explanation-highlighted");
      });
      gameExplanation.classList.add("game-explanation-highlighted");
    });
  }

  var startPlayingLink = document.querySelector(".start-playing-link");
  var gameContainer = document.querySelector(".game-container");

  if (startPlayingLink && gameContainer) {
    startPlayingLink.addEventListener("click", function () {
      gameContainer.scrollIntoView({ behavior: "smooth", block: "center" });
    });
  }
}

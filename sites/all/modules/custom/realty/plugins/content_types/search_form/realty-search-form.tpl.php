<div class="row relative">
  <div class="col-xs-9 fiftyplus big-height poster-photo parent">
    <?php print render($image);?>
  </div>
  <div class="col-xs-3 fiftyminus big-height parent">
    <div class="col-xs-12 beige-block zero-padding">
      <?php if($news_logo):?>
        <div class="col-xs-12 quarter-item zero-padding">
          <?php print $news_logo?>
        </div>
      <?php endif ?>
    </div>
    <div class="col-xs-12 second-quarter-item zero-padding item-text-field">
      <div class="arrow-left"></div>
      <p>
        <?php print $description; ?>
      </p>
      <?php print $details;?>
    </div>
    <div id="search">
    </div>
  </div>
  <?php print render($search_form);?>
  <div id="zk"></div>
</div>
</div>

<div class="modal fade modal-area" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-city zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p><?php print t('Select area')?></p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
       <?php print render($img_close)?>
      </button>
    </div>
    <div class="col-xs-12 list-modal-city">

      <?php foreach($areas as $key => $area):?>
        <div class="col-xs-4">
          <li>
            <label class="checkbox-inline check-style">
              <input type="checkbox" id="inlineCheckbox1" value="<?php print $key?>"><?php print $area; ?>
            </label>
          </li>
        </div>
      <?php endforeach ?>

    </div>
    <div class="col-xs-12 modal-button">
      <a href="#" class="search-button modal-but">Выбрать</a>
    </div>
  </div>
</div>